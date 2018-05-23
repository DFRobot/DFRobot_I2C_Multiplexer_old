#include <DFRobot_I2CMultiplexer.h>


DFRobot_I2CMultiplexer::DFRobot_I2CMultiplexer(uint8_t addr){
  Wire.begin();
  I2CMultiplexer = addr;
}

uint8_t *DFRobot_I2CMultiplexer::scan(uint8_t port){
  static uint8_t dev[127] = {0};
//  uint8_t dev;
  memset(dev,0,sizeof(dev));
  uint8_t i = 0;
  selectPort(port);

  byte error, address;
  int nDevices;
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    if (address == I2CMultiplexer){ continue;}
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0){
      dev[i] = address;
      i++;
    }
  }
  return dev;
}

void DFRobot_I2CMultiplexer::selectPort(uint8_t port){
  if (port > 7) return;
  Wire.beginTransmission(I2CMultiplexer);
  Wire.write(1 << port);
  Wire.endTransmission();
}

uint8_t DFRobot_I2CMultiplexer::write(uint8_t port,uint8_t addr, uint8_t reg,uint8_t* buf, uint8_t len){
  selectPort(port);

  Wire.beginTransmission(addr); // transmit to device #8
  Wire.write(reg);              // sends one byte
  uint8_t i = 0;
  for(i = 0; i < len; i++){
    Wire.write(*buf); 
    buf++;
  }
  Wire.endTransmission();    // stop transmitting
}


uint8_t DFRobot_I2CMultiplexer::read(uint8_t port,uint8_t addr,uint8_t reg,uint8_t* data, uint8_t len){
  selectPort(port);
  int i = 0;
  Wire.beginTransmission(addr); //Start transmission to device 
  Wire.write(reg); //Sends register address to read rom
  Wire.endTransmission(); //End transmission
  
  Wire.requestFrom(addr, len);//Send data n-bytes read
   while (Wire.available())   // slave may send less than requested
  {
    data[i++] = Wire.read(); // print the character
  }
//  Serial.println(result[0]);
  return i;
}