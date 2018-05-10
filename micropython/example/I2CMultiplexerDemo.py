import I2CMultiplexer
from machine import Pin,I2C

I2CMultiAddr = 0x70
port = 0
i2cAddr = 24
nbytes = 3
buf = bytearray(3)
buf[0] = 0
buf[1] = 111
buf[2] = 107

I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)
for Port in range(0,8):
  print("Port:%s" %Port)
  addr = I2CMulti.scan(Port)
  if(len(addr)):
    print("i2c addr:%s" %addr)
I2CMulti.writeto(port,i2cAddr,buf)
msg = I2CMulti.readfrom(port,i2cAddr,nbytes)
print(msg)




