#ifndef _DFRobot_I2CMultiplexer_H_
#define _DFRobot_I2CMultiplexer_H_
#include "Wire.h"
#include <Arduino.h>
//extern "C" { 
//#include "utility/twi.h"  // from Wire library, so we can do bus scanning
//}
class DFRobot_I2CMultiplexer
{
public:
  DFRobot_I2CMultiplexer(uint8_t addr);
  uint8_t *scan(uint8_t port);
  void selectPort(uint8_t port);
  uint8_t read(uint8_t port,uint8_t addr,uint8_t reg,uint8_t* data, uint8_t len);
  uint8_t write(uint8_t port,uint8_t addr, uint8_t reg,uint8_t* buf, uint8_t len);

private:
  uint8_t I2CMultiplexer;
};

#endif