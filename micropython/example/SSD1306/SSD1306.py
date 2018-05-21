#hardware platform: FireBeetle-ESP32

from machine import Pin,I2C
import ssd1306
import I2CMultiplexer

I2CMultiAddr = 0x70     #I2C Multiplexer addr
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr)  #创建I2C Multiplexer对象

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=100000)

#让0端口上的SSD1306显示字符
I2CMulti.selectPort(0)                #选择端口
lcdA=ssd1306.SSD1306_I2C(128,64,i2c)  #创建SSD1306对象
lcdA.text("devicd A",0,0)             #设置字符串及字符串的坐标
lcdA.text("i2c addr 0x3C",0,30)
lcdA.show()                           #display pix

#让1端口上的SSD1306显示字符
I2CMulti.selectPort(1)
lcdB=ssd1306.SSD1306_I2C(128,64,i2c)
lcdB.text("devicd B",0,0)
lcdB.text("i2c addr 0x3C",0,30)
lcdB.show()