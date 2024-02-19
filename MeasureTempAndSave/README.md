# Measure temp and save
Read sensor data from a waterproof DS18B20 temperature sensor through an Arduino Uno connected to your PC via USB and save this data in a .csv file and as a plot at a specified time once per day.

## How it works
When the MeasureTempAndSave.ino code is running on e.g. an Arduino Uno, it continuously outputs temperature data from the connected temperature sensor. The serial_reader_temp.py file runs on your PC and picks up the output at a user-defined delay, saves the values to a .csv file and creates a plot (.png file) once a day.

## Requirements
You need to have the python package [serial](https://pythonhosted.org/pyserial/) installed in your environment.

## Setup and use instructions
- Wire up the Arduino and temperature sensor as shown in the Fritzing image and connect to your computer via USB
- Install the necessary libraries (instructions in the .ino file) and upload the *MeasureTempAndSave.ino* code to the Arduino
- Make a note of which USB port the Arduino is connected to (if it's connected successfully you should find this under "Tools")
- Specify the required values in the 'INPUT' section in *serial_reader_temp.py*
- Run the *serial_reader_temp.py* file in your terminal
- A .csv file with the recorded values and timestamps, plus a plot with the same information, will be saved in the location you specified within *serial_reader_temp.py* once the time you specified has been reached
