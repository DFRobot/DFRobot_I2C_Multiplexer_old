# I2C Multiplexer Library for Arduino/ESP32/RaspberrayPi
This is a Library for I2C Multiplexer,the function is to solve multiple I2C device address conflicts.

## Table of Contents

* [Summary](#summary)
* [Use](#use)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)


<snippet>
<content>

## Summary
This is a Library for I2C Multiplexer,it can solve multiple I2C device address conflicts.The function selectPort() can select a port on I2C Multiplexer.After calling function selectPort(), will scan the I2C device on the port.

## Use

### Arduino
``` C++
#include <Wire.h>
#include <DFRobot_I2CMultiplexer.h>
int I2CAddr = 16;
DFRobot_I2CMultiplexer dev(0x70);
void setup(){
  Serial.begin(9600);
}
void loop(){
  dev.selectPort(1);                    //选择端口后, 主机将会扫描到从机
  Wire.beginTransmission(I2CAddr);
  Wire.write(0x00); 
  Wire.endTransmission();
  Wire.requestFrom(I2CAddr, 4);
  while (Wire.available()){
    Serial.println(Wire.read());
  }
}
```

## Methods

### Arduino
```C++

#include <DFRobot_I2CMultiplexer.h>
/*
 * @brief The constructor
 *
 * @param addr The I2CMultiplexer addr
 */
DFRobot_I2CMultiplexer(uint8_t addr);

/*
 * @brief Scan I2C on the port
 *
 * @param port The port which to scan
 *
 * @return I2C addr buffer
 */
uint8_t *scan(uint8_t port);

/*
 * @brief Read data from I2C
 *
 * @param port The port I2C inserted 
 *        addr 7bit i2c device address
 *        buf  The buffer that receives the data.
 *        len  The length of data received.
 *        sendStop  Boolean indicating whether to send a stop at the end
 *
 * @return number of bytes read
 */
uint8_t read(uint8_t port,uint8_t addr, uint8_t* buf, uint8_t len, uint8_t sendStop=1);

/*
 * @brief write data to I2C
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  7bit i2c device address
 *        buf  Pointer to byte array
 *        len  Number of bytes in array
 *        sendStop  Boolean indicating whether to send a stop at the end
 *        wait  Boolean indicating to wait for write or not
 *        sendStop  Boolean indicating whether or not to send a stop at the end
 *
 * @return 0 success else false
 */
uint8_t write(uint8_t port,uint8_t addr, uint8_t* data, uint8_t len, uint8_t wait=1, uint8_t sendStop=1);

/*
 * @brief Select I2C Port 
 *
 * @param port  I2CMultiplexer port(0~7)
 */
void selectPort(uint8_t port)
```
### micropython
```python

import I2CMultiplexer
/*
 * @brief The constructor.
 *
 * @param I2CMultiAddr The I2CMultiplexer addr.
 */
I2CMultiplexer(I2CMultiAddr)

/*
 * @brief Scan I2C on the port
 * 
 * @param port The port which to scan
 *
 * @return I2C addr buffer
 */
scan(port)

/*
 * @brief write data to I2C.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  7bit i2c device address
 *        buf  write data 
 *
 * @return number of bytes written
 */
writeto(port,addr,buf)

/*
 * @brief read data from I2C.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  7bit i2c device address
 *        buf  The buffer that receives the data. 
 *
 * @return number of bytes read
 */
readfrom(port,addr,nbytes)

/*
 * @brief write data to I2C memory.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  7bit i2c device address
 *        reg  i2c register
 *        buf  write data  
 *
 * @return number of bytes written
 */
writeto_mem(port,addr,reg,buf)

/*
 * @brief read data from I2C memory.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  7bit i2c device address
 *        reg  i2c register
 *        nbytes  Receives the data length. 
 *
 * @return Read data
 */
readfrom_mem(port,addr,reg,nbytes)

/*
 * @brief Select I2C Port 
 *
 * @param port  I2CMultiplexer port(0~7)
 */
selectPort(port)
```
### Raspberry Pi
```python

import I2CMultiplexer
/*
 * @brief The constructor.
 *
 * @param I2CMultiAddr The I2CMultiplexer addr.
 */
I2CMultiplexer(I2CMultiAddr)

/*
 * @brief Scan I2C on the port
 * 
 * @param port The port which to scan
 *
 * @return I2C addr buffer
 */
scan(port)

/*
 * @brief write data to I2C memory.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  7bit i2c device address
 *        reg  i2c register
 *        buf  write data  
 *
 * @return number of bytes written
 */
writeto_mem(port,addr,reg,buf)

/*
 * @brief read data from I2C memory.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  7bit i2c device address
 *        reg  i2c register
 *        nbytes  Receives the data length. 
 *
 * @return Read data
 */
readfrom_mem(port,addr,reg,nbytes)

/*
 * @brief Select I2C Port 
 *
 * @param port  I2CMultiplexer port(0~7)
 */
selectPort(port)
```


## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
FireBeetle-ESP32 |      √       |             |            | 
RaspberrayPi |      √       |             |            | 
Leonardo |      √       |             |            | 

## History

- data 2018-5-9
- version V0.1


## Credits

- author [Luyuhao  <yuhao.lu@dfrobot.com>]
