import I2CMultiplexer
from machine import Pin,I2C

I2CMultiAddr = 0x70     #I2C Multiplexer addr

I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)
for Port in range(0,8):     #Scan the I2C device of each port
  print("Port:%s" %Port)
  addr = I2CMulti.scan(Port)
  if(len(addr)):
    print("i2c addr:%s" %addr)




