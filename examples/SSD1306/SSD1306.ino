 /*!
  * file read_MAX31855.ino
  * 
  * 下载SSD1306的库 https://github.com/DFRobot/DFRobot_SSD1306.git
  * 
  * 将2个SSD1306设备分别接到I2CMultiplexer的0端口和1端口上,然后连接I2CMultiplexer和Arduino,下载此示例
  * @n 可以看到SSD1306显示设备名称和I2C地址.
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V0.1
  * date  2018-5-10
  */
#include "DFRobot_SSD1306_I2C.h"
#include "DFRobot_I2CMultiplexer.h"
#include <Wire.h>

/*创建一个OLED对象，地址为0x3c*/
DFRobot_SSD1306_I2C OLED(0x3c);

/*创建I2C Multiplexer对象, 0x70是I2C Multiplexer的地址*/
DFRobot_I2CMultiplexer I2CMulti(0x70);


void setup(void){
  /*让0端口上的OLED显示字符*/
  I2CMulti.selectPort(0);       //选择端口
  OLED.begin();                 //OLED初始化
  OLED.setTextColor(1);
  OLED.setTextSize(2);
  
  OLED.setCursor(0,0);          //设置字符坐标
  OLED.print("device A");      //显示字符
  OLED.setCursor(0,30);
  OLED.print("addr:0x3C");

  /*让1端口上的OLED显示字符*/
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
