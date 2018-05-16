#download the library of MAX31855 https://github.com/DFRobot/DFRobot_MAX31855.git

import DFRobot_MAX31855
import I2CMultiplexer
import time

#I2C Multiplexer addr
I2CMultiAddr = 0x70   

#Create MAX31855 object
max31855 = DFRobot_MAX31855.DFRobot_MAX31855()  

#Create an I2CMultiplexer object,0x70 is I2C Multiplexer addr
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)

#Select port 2 which MAX31855 on this port
I2CMulti.selectPort(2)

#Read celsius
while True:
  temp = max31855.readCelsius()                 
  print("Temperature:%s *C" %temp)
  time.sleep(1)
    