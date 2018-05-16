#download the library of MAX31855 https://github.com/DFRobot/DFRobot_MAX31855.git

from machine import Pin,I2C
import MAX31855
import time 
import I2CMultiplexer

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=10000)

max31855 = MAX31855.MAX31855(i2c)   #创建一个 MAX31855 对象
i2cdev = I2CMultiplexer.I2CMultiplexer(0x70)  #创建一个I2CMultiplexer对象,0x70是I2C Multiplexer的地址
i2cdev.selectPort(2)                #选择端口2后则会扫描的端口2上的I2C设备
while True:
  if(max31855.scan() == True):      #Detect i2c device
    temp = max31855.readCelsius()   #Read Celsius
    print("Temperature:%s C" %temp)
  else:                             #No I2C was detected.
    print("No I2C devices!")
  time.sleep(1)




