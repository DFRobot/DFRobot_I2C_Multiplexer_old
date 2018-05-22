import I2CMultiplexer
from machine import Pin,I2C

I2CMultiAddr = 0x70     #I2C Multiplexer addr
port = 0                #I2C device is connected to port 0
i2cAddr = 24            #The address of I2C 
            
buf = bytearray(3)      #The information that will be sent
buf[0] = 0
buf[1] = 111
buf[2] = 107

nbytes = 3              #The length of received data 

#Create an I2CMultiplexer object, the address of I2CMultiplexer is 0X70
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)  
I2CMulti.writeto(port,i2cAddr,buf)            #Write buf to I2c device on port 0
msg = I2CMulti.readfrom(port,i2cAddr,nbytes)  #Read 3-byte length messages from the I2C device on port 0
print(msg)




