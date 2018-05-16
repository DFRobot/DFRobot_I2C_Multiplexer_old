import I2CMultiplexer

I2CMultiAddr = 0x70     #I2C Multiplexer addr
port = 0                #I2C设备接的端口为0

i2cDevAddr = 24         #I2C device addr
reg = 0                 #I2C register addr

buf = [111,107]         #将要发送的消息
nbytes = 3              #接收消息的长度

#创建一个I2CMultiplexer对象,0x70是I2C Multiplexer的地址
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)  

#向0端口上的I2C设备的reg寄存器写入buf
I2CMulti.writeto_mem(port,i2cDevAddr,reg,buf)


#从0端口上的I2C设备的reg寄存器读取3个字节长度的消息
data = I2CMulti.readfrom_mem(port,i2cDevAddr,reg,nbytes)
print(data)