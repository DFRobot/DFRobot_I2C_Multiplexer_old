#download the library of MAX31855 https://github.com/DFRobot/DFRobot_MAX31855.git

from machine import Pin,I2C
import MAX31855
import time 
import I2CMultiplexer

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=10000)

max31855 = MAX31855.MAX31855(i2c)   #Create a MAX object 
i2cdev = I2CMultiplexer.I2CMultiplexer(0x70) #Create an I2C Multiplexer object, the address of I2C Multiplexer is 0X70
i2cdev.selectPort(2)                #I2C device on the port 2 will be scanned after select port 2
while True:
  if(max31855.scan() == True):      #Detect i2c device
    temp = max31855.readCelsius()   #Read Celsius
    print("Temperature:%s C" %temp)
  else:                             #No I2C was detected.
    print("No I2C devices!")
  time.sleep(1)




