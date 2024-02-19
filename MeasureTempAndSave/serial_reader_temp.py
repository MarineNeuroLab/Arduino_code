"""
Read sensor data from a waterproof DS18B20 temperature sensor through an Arduino Uno connected to your PC via USB
and save this data in a .csv file and as a plot at a specified time once per day
Note: the filename for the .csv file contains the time when that file was created,
while the filename for the plot (.png file) contains the time when the measurements *finished* saving to file

Inspired by https://makersportal.com/blog/2018/2/25/python-datalogger-reading-the-serial-output-from-arduino-to-analyze-data-using-pyserial
and
https://github.com/kavli-ntnu/wheel_tracker/blob/master/save_tracking.py
"""

####### INPUT ######################################################################
# Specify which folder to save the data in
root_folder = 'C:/DATA/Sensor_data' 

# Specify the time (in 24hr clock format) when a new file should be made (e.g. every day at midnight)
newfile_hour = 0
newfile_min = 0

# Specify the delay between measurements to be saved (in seconds) 
# NOTE: this is not precise as it doesn't take into consideration the time it takes to run the code itself
# Range: 0.5-50 seconds
delay = 1

# Speciy which port to read the data from (i.e. the USB port the Arduino is connected to)
port = 'COM11'
####################################################################################

import serial
from datetime import datetime
import time
import matplotlib.pyplot as plt
import numpy as np

ser = serial.Serial(port) #Specify which port to read from 
ser.flushInput() #This clears the serial buffer so everything is ready to go

# Main code:
while True: #While True, run the following code to record and save temperature values in  the output file specified
    # Get the current time
    now = datetime.now().strftime('%Y-%m-%d_%H-%M-%S')
    
    # Create a cvs file with a name based on the current time in the root folder specified 
    output_file='{}/{}_temp.csv'.format(root_folder, now)

    #Create empty lists to save measurements in (for plotting later)
    timevec=[]
    tempvec=[]

    with open(output_file,"a") as f: #Open the file
        f.write('Timestamp,Temperature in degrees C\n') #Add headers to the file
        timestart = datetime.now().strftime('%Y-%m-%d_%H:%M:%S.%f') #Save the current time as a string, just before measurements start being saved
        timenow = datetime.now() #Save the current time, which will refresh regularly through the script

        # While the current time is NOT the set newfile_hour/min time, continuously save data to the file
        while timenow.hour != newfile_hour or timenow.minute != newfile_min:
            ser_bytes = ser.readline() #Read one line from the port
            decoded_bytes = ser_bytes.decode('utf-8') #Convert the read data so it's legible
            decoded_bytes_split = decoded_bytes.strip().split(',') #Strip away the prefix and suffix characters, and split the values using the comma as the separator

            # Extract the temperature value and convert it to a float
            temp_value = float(decoded_bytes_split[0])

            # Get the current time (as a string)
            now = datetime.now().strftime('%Y-%m-%d_%H:%M:%S.%f')
           
            # Save the values in the csv file and in the lists
            f.write('{},{}\n'.format(now[0:-4],temp_value))
            timevec.append(now[0:-4])
            tempvec.append(temp_value)

            # Print out the values in the terminal
            print('{} | Temp: {} degrees C'.format(now[0:-4],temp_value))         

            # Introduce the specified delay to only record values roughly every X seconds
            time.sleep(delay)
            
            # Get the current time so the while loop can be evaluated again (is it appropriate to stay in the loop or exit it?)
            timenow = datetime.now()
            
    # Once the while loop has been exited, print a status update in the terminal
    timeend = datetime.now().strftime('%Y-%m-%d_%H-%M-%S.%f') # Get the current time (as a string)
    print('Temperature measurements started saving just after {}, finished saving at {}'.format(timestart[0:-7],timeend[0:-7]))
    print('Recording will continue in about 1 minute \n \n')

    # Create and save a plot of the values collected
    figure = plt.figure() #Create a plot
    ax = figure.add_subplot(111)
    ax.plot(timevec, tempvec,'-')   

    plt.xticks([0, np.floor(len(timevec)/2),len(timevec)-1])
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    
    plt.xlabel("Time")
    plt.ylabel("Temperature in degrees C")
    plt.savefig('{}/{}.png'.format(root_folder,timeend[0:-7]),dpi=300)
    
    # Include a break to avoid making unnecessary new files when the specified delay is shorter than a minute
    time.sleep(59)
