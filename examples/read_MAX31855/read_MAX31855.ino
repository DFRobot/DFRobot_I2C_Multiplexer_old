 /*!
  * file read_MAX31855.ino
  * 
  * download MAX31855 library https://github.com/DFRobot/DFRobot_MAX31855.git
  * 
  * Connect MAX31855 to I2CMultiplexer, and connect I2CMultiplexer to Arduino, then download this example.
  * @n open serial monitor to check the temperature.
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V0.1
  * date  2018-5-10
  */
  
#include <DFRobot_MAX31855.h>
#include <DFRobot_I2CMultiplexer.h>

/*Create a MAX31855 object*/
DFRobot_MAX31855 max31855;

/*Create an I2C Multiplexer object, 0x70 is I2C Multiplexer addr*/
DFRobot_I2CMultiplexer I2CMultiplexer(0x70);


void setup(){
  Serial.begin(9600);
}

void loop(){
  int stat;
  
  /*Select port 2 because MAX31855 on this port*/
  I2CMultiplexer.selectPort(2);
  
  /*Detect I2C device*/
  stat = max31855.scan();
  if(!stat){
    Serial.println("No I2C devices!");
  }
  else{
    /*Read Celsius*/
    float temp = max31855.readCelsius();
    Serial.print("Temperature:");
    Serial.print(temp);
    Serial.println(" *C");
  }
  delay(1000);
}