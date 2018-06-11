 /*!
  * file Multi_SSD1306.ino
  * 
  * Download Display library https://github.com/DFRobot/DFRobot_Display.git
  * Download SSD1306 library https://github.com/DFRobot/DFRobot_SSD1306.git 
  * 
  * Connect the 2 SSD1306 devices to the port 0 and  port 1 on the i2cmultiplexer respectively and then connect the I2cmultiplexer and Arduino, download this sample. 
  * @n The address of I2C and the name of SSD1306 display module can be seen 
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V0.1
  * date  2018-5-10
  */
#include "DFRobot_SSD1306_I2C.h"
#include "DFRobot_I2CMultiplexer.h"
#include "DFRobot_Character.h"
#include "DFRobot_GT30L.h"
#include <Wire.h>
#include <SPI.h>

/*Create an OLED object, the address is 0x3c*/ 
DFRobot_SSD1306_I2C OLED(0x3c);

/*Create an I2C Multiplexer object, the address of I2C Multiplexer is 0X70*/ 
DFRobot_I2CMultiplexer I2CMulti(0x70);


void setup(void){
  /*Let the OLED on port 0 display characters*/
  I2CMulti.selectPort(0);       //Select port
  OLED.begin();                 //initialize OLED
  OLED.setTextColor(1);
  OLED.setTextSize(2);
  
  OLED.setCursor(0,0);          // Set the corrdianate of characters
  OLED.print("device A");       //Display characters 
  OLED.setCursor(0,30);
  OLED.print("addr:0x3C");

  /*Let OLED on  port 1 display  characters */
  I2CMulti.selectPort(1);
  OLED.begin();
  OLED.setTextColor(1);
  OLED.setTextSize(2);
  
  OLED.setCursor(0,0);
  OLED.print("device B");
  OLED.setCursor(0,30);
  OLED.print("addr:0x3C");
}

void loop(void){
}
