import I2CMultiplexer

I2CMultiAddr = 0x70     #I2C Multiplexer addr
port = 0                #There is an I2C device of port 0

i2cDevAddr = 24         #I2C device addr
reg = 0                 #I2C register addr

buf = [111,107]         #Write data
nbytes = 3              #Read data length

#Create an I2CMultiplexer object,0x70 is I2C Multiplexer addr
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)  

#write buf to memory of i2c on port 0
I2CMulti.writeto_mem(port,i2cDevAddr,reg,buf)


#read 3 bytes from reg of I2C on port 0
data = I2CMulti.readfrom_mem(port,i2cDevAddr,reg,nbytes)
print(data)