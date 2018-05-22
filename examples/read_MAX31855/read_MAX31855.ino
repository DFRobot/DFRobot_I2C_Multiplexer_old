 /*!
  * file read_MAX31855.ino
  * 
  * Download MAX31855 library https://github.com/DFRobot/DFRobot_MAX31855.git
  * 
  * Plug MAX31855 device onto 2 port of I2CMultiplexer,and then connect I2CMultiplexer and Arduino, download the sample
  * @n  The temperature can be seen after you open serial 
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V0.1
  * date  2018-5-10
  */
  
#include <DFRobot_MAX31855.h>
#include <DFRobot_I2CMultiplexer.h>

/* Create a  MAX31855 object*/
DFRobot_MAX31855 max31855;

/*Create an I2C Multiplexer object,the address of I2C Multiplexer is 0X70*/
DFRobot_I2CMultiplexer I2CMultiplexer(0x70);


void setup(){
  Serial.begin(9600);
}

void loop(){
  int stat;
  
  /*Select port 2, and after calling this function, Arduino will scan the MAX31855 device on port 2*/
  I2CMultiplexer.selectPort(2);
  
  /*Detect I2C device*/
  stat = max31855.scan();
  if(!stat){
    Serial.println("No I2C devices!");
  }
  else{
    /*Read temperature*/
    float temp = max31855.readCelsius();
    Serial.print("Temperature:");
    Serial.print(temp);
    Serial.println(" *C");
  }
  delay(1000);
}
