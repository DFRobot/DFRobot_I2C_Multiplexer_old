#download the library of MAX31855 https://github.com/DFRobot/DFRobot_MAX31855.git

import DFRobot_MAX31855
import I2CMultiplexer
import time

#I2C Multiplexer addr
I2CMultiAddr = 0x70   

#Create MAX31855 object
max31855 = DFRobot_MAX31855.DFRobot_MAX31855()  

#创建一个I2CMultiplexer对象,0x70是I2C Multiplexer的地址
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)

#选择端口2后则会扫描的端口2上的I2C设备
I2CMulti.selectPort(2)

#Read celsius
while True:
  temp = max31855.readCelsius()                 
  print("Temperature:%s *C" %temp)
  time.sleep(1)
    