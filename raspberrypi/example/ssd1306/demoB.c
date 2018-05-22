/******
Demo for ssd1306 i2c driver for  Raspberry Pi 
******/

#include "ssd1306.h"

void main() {

	ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
	ssd1306_clearDisplay();

	char* text1 = "device B";
	char* text2 = "addr 0x3c";
	ssd1306_String(0,0,text1);
	ssd1306_String(0,30,text2);
	ssd1306_display();
}
