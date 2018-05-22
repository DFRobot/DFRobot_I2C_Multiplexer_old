import ssd1306
import I2CMultiplexer

I2CMultiAddr = 0x70     #I2C Multiplexer addr
I2CMulti = I2CMultiplexer.I2CMultiplexer(I2CMultiAddr) 

text1 = "device A"
text2 = "device B"

#Let the SSD1306 on the port 0 display characters 
I2CMulti.selectPort(0)            #Select port
ssd1306.ssd1306_begin(0x3c)       #Init SSD1306
ssd1306.ssd1306_clearDisplay()    #clear everything
ssd1306.ssd1306_String(0,0,text1,2)   #set string 'text1' at (0,0),The font size is 2
ssd1306.ssd1306_String(0,30,"addr 0x3c",2)
ssd1306.ssd1306_display();        #display

#Let SSD1306 on port 1 display characters
I2CMulti.selectPort(1)
ssd1306.ssd1306_begin(0x3c)
ssd1306.ssd1306_clearDisplay()
ssd1306.ssd1306_String(0,0,text2,2)
ssd1306.ssd1306_String(0,30,"addr 0x3c",2)
ssd1306.ssd1306_display();

