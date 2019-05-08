import serial
from time import sleep
'''
ser = serial.Serial("COM8",115200)
print(ser.readline())
print(ser.readline())
'''
file = open("test.gcode") #開檔

x = file.readlines()

for i in x:
    print(i)