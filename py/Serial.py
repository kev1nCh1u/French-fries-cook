import serial
ser = serial.Serial("COM8",115200)
from time import sleep
print(ser.readline())
print(ser.readline())
while True:
 cmd = input('enter: ')

 print(f'GoTo: {cmd}')
 cmd += '\n'
 ser.write(cmd.encode())

 print(ser.readline())
 print(ser.readline())
 print(ser.readline())
 print(ser.readline())

 sleep(1)


