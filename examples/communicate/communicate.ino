#include <DFRobot_I2CMultiplexer.h>
DFRobot_I2CMultiplexer I2CMultiplexer(0x70);

uint8_t port = 0;
uint8_t i2c_addr = 24;

void setup(){
  Serial.begin(9600);
}

void loop(){
  uint8_t buf[3] = {0}; 
  if(I2CMultiplexer.read(port,i2c_addr,buf,3) > 0){
    Serial.println((int)buf[0],HEX);  
    Serial.println((int)buf[1],HEX);
    Serial.println((int)buf[2],HEX);
  }
  uint8_t data[3] = {0,111,107};
  if (!I2CMultiplexer.write(port,i2c_addr, data, 3)) {
     Serial.println("write OK");
  }
  delay(1000);
}