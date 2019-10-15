import serial
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import time

def start_serial(com,baud):
    """
    Initialize the serial port to receive arduino data.
    
    Args:
        com: COM port to start the serial communication with
        baud: baud rate
    
    Return:
        serialPort: the opened serial port
    """
    arduinoComPort = com
    baudRate = baud
    serialPort = serial.Serial(arduinoComPort, baudRate, timeout=1)
    return serialPort

def live_plot():
    """
    Parse the information in the serial port. Plot the data on an azimuth by elevation graph with depth being the color bar.
    """
    
    #start reading from the serial port
    serialPort = start_serial("COM7",9600) 
    time.sleep(2)
    
    fig, ax1 = plt.subplots()
    ax1.set_xlabel('Time (s)')
    ax1.set_ylabel('IR Sensor Data')

    ax2 = ax1.twinx()

    ax2.set_ylabel('Motor Speeds')


    time_array = []
    IR_left_array = []
    IR_right_array = []
    motor_left_array = []
    motor_right_array = []
    try:
        while serialPort.isOpen() is True:
            lineOfData = serialPort.readline().decode()
            if lineOfData is not '\n': # skip the case when the only output is a new line on the serial port
                # parse the information into plottable data
                point = lineOfData.split(',')
                timei = point[0]
                IR_left= int(point[1])
                IR_right = int(point[2])
                motor_left = int(point[3])
                motor_right = int(point[4])   

                time_array.append(timei)
                IR_left_array.append(IR_left)
                IR_right_array.append(IR_right)
                motor_left_array.append(motor_left)
                motor_right_array.append(motor_right)
    except KeyboardInterrupt:
        pass
    

    ax1.plot(time_array, IR_left_array)
    ax1.plot(time_array,IR_right_array)

    ax1.legend(['Left IR Sensor', 'Right IR Sensor'], loc = 'best')

    ax2.plot(time_array, motor_left_array)
    ax2.plot(time_array,motor_right_array)
    ax2.legend(['Left Motor Speeds', 'Right Motor Speeds'], loc = 'best')
    

    plt.show()

live_plot()