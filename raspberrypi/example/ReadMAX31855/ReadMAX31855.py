#download the library of MAX31855 https://github.com/DFRobot/DFRobot_MAX31855.git

import DFRobot_MAX31855
import I2CMultiplexer
import time

#I2C Multiplexer addr
I2CMultiAddr = 0x70   

#Create MAX31855 object
max31855 = DFRobot_MAX31855.DFRobot_MAX31855()  

#Create an I2C Multiplexer object, the address of I2C Multiplexer is 0X70
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)

#It will Scan I2C device on port 2 after select port 2
I2CMulti.selectPort(2)

#Read celsius
while True:
  temp = max31855.readCelsius()                 
  print("Temperature:%s *C" %temp)
  time.sleep(1)
    