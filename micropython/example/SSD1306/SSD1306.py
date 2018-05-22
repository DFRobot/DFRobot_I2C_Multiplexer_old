#hardware platform: FireBeetle-ESP32

from machine import Pin,I2C
import ssd1306
import I2CMultiplexer

I2CMultiAddr = 0x70     #I2C Multiplexer addr
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)  #Create an I2CMultiplexer object

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=100000)

#Let the SSD1306 on the port 0 display characters 
I2CMulti.selectPort(0)                #Select port
lcdA=ssd1306.SSD1306_I2C(128,64,i2c)  #Create a SSD1306 Object
lcdA.text("devicd A",0,0)             #Set the coordinate of character string and character 
lcdA.text("i2c addr 0x3C",0,30)
lcdA.show()                           #display pix

#Let SSD1306 on port 1 display characters 
I2CMulti.selectPort(1)
lcdB=ssd1306.SSD1306_I2C(128,64,i2c)
lcdB.text("devicd B",0,0)
lcdB.text("i2c addr 0x3C",0,30)
lcdB.show()