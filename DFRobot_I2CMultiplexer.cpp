#include "Wire.h"
#include <Arduino.h>
#include <DFRobot_I2CMultiplexer.h>
extern "C" { 
#include "utility/twi.h"  // from Wire library, so we can do bus scanning
}



DFRobot_I2CMultiplexer::DFRobot_I2CMultiplexer(uint8_t addr){
  Wire.begin();
  I2CMultiplexer = addr;
}

uint8_t* DFRobot_I2CMultiplexer::scan(uint8_t port){
//  static uint8_t dev[8] = {0};
  uint8_t dev;
  memset(dev,0,sizeof(dev));
  uint8_t i = 0;
  selectPort(port);
  for(uint8_t addr = 0; addr<=127; addr++) {
    if (addr == I2CMultiplexer){ continue;}
    uint8_t data;
    if(! twi_writeTo(addr, &data, 0, 1, 1)) {
//       dev[i] = addr;
//       i++;
      dev = addr;
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

/*
 * Input    port: I2CMultiplexer port(0~7)
 *          address: 7bit i2c device address
 *          data: pointer to byte array
 *          length: number of bytes to read into array
 *          sendStop: Boolean indicating whether to send a stop at the end
 * Output   number of bytes read
 */
uint8_t DFRobot_I2CMultiplexer::read(uint8_t port,uint8_t addr, uint8_t* buf, uint8_t len, uint8_t sendStop=1){
  selectPort(port);
  return twi_readFrom(addr,buf,len,sendStop);
}

/*
 * Input    port: I2CMultiplexer port(0~7)
 *          address: 7bit i2c device address
 *          data: pointer to byte array
 *          length: number of bytes in array
 *          wait: boolean indicating to wait for write or not
 *          sendStop: boolean indicating whether or not to send a stop at the end
 * Output   0 .. success
 *          1 .. length to long for buffer
 *          2 .. address send, NACK received
 *          3 .. data send, NACK received
 *          4 .. other twi error (lost bus arbitration, bus error, ..)
 */
uint8_t DFRobot_I2CMultiplexer::write(uint8_t port,uint8_t address, uint8_t* data, uint8_t length, uint8_t wait=1, uint8_t sendStop=1){
  selectPort(port);
  return twi_writeTo(address,data,length,wait,sendStop);
}