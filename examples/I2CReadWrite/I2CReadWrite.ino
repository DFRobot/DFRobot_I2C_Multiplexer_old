 /*!
  * file I2CReadWrite.ino
  * 
  * Plug the I2C device onto the 0 port of I2cmultiplexer ,then connect i2cmultiplexer and Arduino, and download the sample.
  * @n The information can be seen after you open serial. 
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V0.1
  * date  2018-5-10
  */

#include <DFRobot_I2CMultiplexer.h>
#include <Wire.h>

/*Create an I2CMultiplexer object,and the address of I2CMultiplexer is 0X70*/
DFRobot_I2CMultiplexer I2CMultiplexer(0x70);

/*Plug I2C device onto port 0*/
uint8_t port = 0;

/*The address of I2C is 24*/
uint8_t i2c_addr = 24;

/*The register address of I2C*/
uint8_t reg = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  uint8_t buf[3] = {0}; 
  
  /*Read 3 bytes from the 0 register of the I2C device on port 0 into the buf, then prints the data from the buf in hexadecimal order*/
  if(I2CMultiplexer.read(port,i2c_addr,reg,buf,3) > 0){
    Serial.println((int)buf[0],HEX);  
    Serial.println((int)buf[1],HEX);
    Serial.println((int)buf[2],HEX);
  }
  
  /*Wirte the data of I2C*/ 
  uint8_t data[2] = {111,107};
  
  /*Write data to the 0 register of the I2C device on port 0, the length of data is 3*/
  I2CMultiplexer.write(port,i2c_addr,reg, data, 2);
  delay(1000);
}
