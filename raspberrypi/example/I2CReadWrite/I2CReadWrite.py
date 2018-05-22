import I2CMultiplexer

I2CMultiAddr = 0x70     #I2C Multiplexer addr
port = 0                #The I2C device is connected to  port 0

i2cDevAddr = 24         #I2C device addr
reg = 0                 #I2C register addr

buf = [111,107]         #The information will be sent 
nbytes = 3              #The length of received data

#Create an I2C Multiplexer object, the address of I2C Multiplexer is 0X70
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)  

#Write buf to the Reg register of the I2C device on port 0
I2CMulti.writeto_mem(port,i2cDevAddr,reg,buf)


#Read message of 3 bytes length from the Reg register of the I2C device on Port 0.
data = I2CMulti.readfrom_mem(port,i2cDevAddr,reg,nbytes)
print(data)