import I2CMultiplexer
from machine import Pin,I2C

I2CMultiAddr = 0x70     #I2C Multiplexer addr
port = 0                #There is a i2c device of port 0
i2cAddr = 24            #I2C device addr
            
buf = bytearray(3)      #The buf will to be sent
buf[0] = 0
buf[1] = 111
buf[2] = 107

nbytes = 3              #The length of message

#Create an I2CMultiplexer object,0x70 is I2C Multiplexer addr
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)  
I2CMulti.writeto(port,i2cAddr,buf)            #Write buf to i2c of port 0
msg = I2CMulti.readfrom(port,i2cAddr,nbytes)  #read nbytes message from i2c device of port 0
print(msg)




