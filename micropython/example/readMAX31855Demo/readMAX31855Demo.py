#download the library of MAX31855 https://github.com/DFRobot/DFRobot_MAX31855.git

from machine import Pin,I2C
import MAX31855
import time 
import I2CMultiplexer

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=10000)

max31855 = MAX31855.MAX31855(i2c)   #Create a MAX31855 object
i2cdev = I2CMultiplexer.I2CMultiplexer(0x70)  #Create an I2CMultiplexer object,0x70 is I2C Multiplexer addr
i2cdev.selectPort(2)                #Select port 2 which MAX31855 on the port
while True:
  if(max31855.scan() == True):      #Detect i2c device
    temp = max31855.readCelsius()   #Read Celsius
    print("Temperature:%s C" %temp)
  else:                             #No I2C was detected.
    print("No I2C devices!")
  time.sleep(1)




