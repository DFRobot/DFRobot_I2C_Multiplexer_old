 /*!
  * file I2CReadWrite.ino
  * 
  * Connect I2C devices to I2CMultiplexer, and connect I2CMultiplexer to Arduino, then download this example
  * @n open serial monitor to check the data.
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V0.1
  * date  2018-5-10
  */

#include <DFRobot_I2CMultiplexer.h>

/*0x70 is I2C Multiplexer addr*/
DFRobot_I2CMultiplexer I2CMultiplexer(0x70);

/*There is an i2c device on port 0*/
uint8_t port = 0;

/*This i2c address is 24*/
uint8_t i2c_addr = 24;

void setup(){
  Serial.begin(9600);
}

void loop(){
  uint8_t buf[3] = {0}; 
  
  /*Read 3 bytes from i2c on port 0 to buf*/
  if(I2CMultiplexer.read(port,i2c_addr,buf,3) > 0){
    Serial.println((int)buf[0],HEX);  
    Serial.println((int)buf[1],HEX);
    Serial.println((int)buf[2],HEX);
  }
  
  uint8_t data[3] = {0,111,107};
  
  /*write array to i2c, the length of array is 3*/
  if (!I2CMultiplexer.write(port,i2c_addr, data, 3)) {
     Serial.println("write OK");
  }
  delay(1000);
}