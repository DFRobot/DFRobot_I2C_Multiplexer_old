#ifndef _DFRobot_I2CMultiplexer_H_
#define _DFRobot_I2CMultiplexer_H_

class DFRobot_I2CMultiplexer
{
public:

  DFRobot_I2CMultiplexer(uint8_t addr);
  uint8_t *scan(uint8_t port);
  void select(uint8_t i);
  uint8_t read(uint8_t port,uint8_t addr, uint8_t* buf, uint8_t len, uint8_t sendStop=1);
  uint8_t write(uint8_t port,uint8_t address, uint8_t* data, uint8_t length, uint8_t wait=1, uint8_t sendStop=1);

private:
  uint8_t I2CMultiplexer = 0x70;
};

#endif