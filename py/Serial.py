import serial
s=serial.Serial("com4",9600)
from time import sleep
while True:
 s.write('H'.encode())
 sleep(1)
 s.write('L'.encode())
 sleep(1)
