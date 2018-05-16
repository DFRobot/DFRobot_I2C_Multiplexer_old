import I2CMultiplexer
from machine import Pin,I2C

I2CMultiAddr = 0x70     #I2C Multiplexer addr
port = 0                #I2C设备接的端口为0
i2cAddr = 24            #I2C设备的地址
            
buf = bytearray(3)      #将要发送的消息
buf[0] = 0
buf[1] = 111
buf[2] = 107

nbytes = 3              #接收消息的长度

#创建一个I2CMultiplexer对象,0x70是I2C Multiplexer的地址
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)  
I2CMulti.writeto(port,i2cAddr,buf)            #向0端口上的I2C设备写入buf
msg = I2CMulti.readfrom(port,i2cAddr,nbytes)  #从0端口上的I2C设备读取3个字节长度的消息
print(msg)




