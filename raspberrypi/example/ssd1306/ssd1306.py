import os
import I2CMultiplexer

I2CMultiAddr = 0x70     #I2C Multiplexer addr
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)  #Create an I2CMultiplexer object

#Let the SSD1306 on the port 0 display characters 
I2CMulti.selectPort(0)      #Select port 
os.system('./ssd1306A')     #Execute demo ssd1306A


I2CMulti.selectPort(1)     
os.system('./ssd1306B')
