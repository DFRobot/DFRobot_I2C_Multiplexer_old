import I2CMultiplexer

port = 0
reg = 0
nbytes = 3
i2cDevAddr = 24
I2CMultiAddr = 0x70

I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)
for Port in range(0,8):
  print("Port:%s" %Port)
  addr = I2CMulti.scan(Port)
  if(len(addr)):
    print("i2c addr:%s" %addr)

buf = [111,107]
I2CMulti.writeto_mem(port,i2cDevAddr,reg,buf)
data = I2CMulti.readfrom_mem(port,i2cDevAddr,reg,nbytes)
print(data)