 /*!
  * file read_MAX31855.ino
  * 
  * 下载MAX31855的库 https://github.com/DFRobot/DFRobot_MAX31855.git
  * 
  * 将MAX31855设备插到I2CMultiplexer的2端口上,然后连接I2CMultiplexer和Arduino,下载此示例
  * @n 打开串口监视器可以看到温度.
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V0.1
  * date  2018-5-10
  */
  
#include <DFRobot_MAX31855.h>
#include <DFRobot_I2CMultiplexer.h>

/*创建一个MAX31855对象*/
DFRobot_MAX31855 max31855;

/*创建I2C Multiplexer对象, 0x70是I2C Multiplexer的地址*/
DFRobot_I2CMultiplexer I2CMultiplexer(0x70);


void setup(){
  Serial.begin(9600);
}

void loop(){
  int stat;
  
  /*选择端口2,调用此函数后Arduino将会扫描到端口2上的MAX31855设备*/
  I2CMultiplexer.selectPort(2);
  
  /*检测I2C设备*/
  stat = max31855.scan();
  if(!stat){
    Serial.println("No I2C devices!");
  }
  else{
    /*读取温度*/
    float temp = max31855.readCelsius();
    Serial.print("Temperature:");
    Serial.print(temp);
    Serial.println(" *C");
  }
  delay(1000);
}