# I2C Multiplexer Library for Arduino/ESP32/RaspberrayPi
This is a Library for I2C Multiplexer,the function is to solve multiple I2C device address conflicts.


![image](https://github.com/DFRobot/DFRobot_I2C_Multiplexer/blob/master/image/top.jpg)
![image](https://github.com/DFRobot/DFRobot_I2C_Multiplexer/blob/master/image/bottom.jpg)
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
* This is I2C Multiplexer library, I2C Multiplexer can solve the conflict that multiple devices with the same address.
* There is 8 ports on I2C Multiplexer, when the Selectport (n) function is called to select a port, the host can communicate with slave that has been connected to the sub port. 
* The dial switch on I2C Multiplexer can change the address of I2C Multiplexer.
* Multiple devices can also be connected on I2C Multiplexer's sub ports.

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
  dev.selectPort(1);                    // After select port, the host can communicate with the slave on this port.
  Wire.beginTransmission(I2CAddr);
  Wire.write(0x00); 
  Wire.endTransmission();
  Wire.requestFrom(I2CAddr, 4);
  while (Wire.available()){
    Serial.println(Wire.read());
  }
}
```

### Be used for SSD1306 module 
``` C++
#include "DFRobot_SSD1306_I2C.h"
#include "DFRobot_I2CMultiplexer.h"
#include <Wire.h>

/*Create an OLED object, the address is 0X3C*/
DFRobot_SSD1306_I2C OLED(0x3c);

/*Create an I2C Multiplexer object, the address of I2CMultiplexer is 0X70*/
DFRobot_I2CMultiplexer I2CMulti(0x70);


void setup(void){
  /*Let the OLED on port 0 display characters */
  I2CMulti.selectPort(0);       //Select port 
  OLED.begin();                 //initialize OLED
  OLED.setTextColor(1);
  OLED.setTextSize(2);
  
  OLED.setCursor(0,0);          //Set the coordinate of characters 
  OLED.print("device A");       //Display characters 
  OLED.setCursor(0,30);
  OLED.print("addr:0x3C");

  /*Let the OLED on port 1 display characters */
  I2CMulti.selectPort(1);
  OLED.begin();
  OLED.setTextColor(1);
  OLED.setTextSize(2);
  
  OLED.setCursor(0,0);
  OLED.print("device B");
  OLED.setCursor(0,30);
  OLED.print("addr:0x3C");
}

void loop(void){
}
```
![image](https://github.com/DFRobot/DFRobot_I2C_Multiplexer/blob/master/image/ssd1306.png)


## Methods

### Arduino
```C++

#include <DFRobot_I2CMultiplexer.h>
/*
 * @brief The constructor
 *
 * @param addr The I2CMultiplexer addr, default address is 0x70.
 */
DFRobot_I2CMultiplexer(uint8_t addr);

/*
 * @brief Scan I2C on the port
 *
 * @param port The port which to scan
 *
 * @return The assemblage of all I2C addresses on the port
 */
uint8_t *scan(uint8_t port);

/*
 * @brief Read data from I2C
 *
 * @param port  The port I2C inserted 
 *        addr  7bit I2C device address
 *        reg   I2C register addr
 *        data  Pointer to byte array
 *        len   The length of data received.
 *
 * @return number of bytes read
 */
uint8_t read(uint8_t port,uint8_t addr,uint8_t reg,uint8_t* data, uint8_t len);

/*
 * @brief write data to I2C
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  7bit I2C device address
 *        reg   I2C register addr
 *        buf   Pointer to byte array
 *        len   Number of bytes in array
 */
uint8_t write(uint8_t port,uint8_t addr, uint8_t reg,uint8_t* buf, uint8_t len);

/*
 * @brief After select port, the host can communicate with the slave on this port.
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
 * @param I2CMultiAddr The I2CMultiplexer addr, default address is 0x70.
 */
I2CMultiplexer(I2CMultiAddr)

/*
 * @brief   Scan I2C on the port
 * 
 * @param   port The port which to scan
 *
 * @return  I2C addr buffer
 */
scan(port)

/*
 * @brief write data to I2C.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  i2c device address
 *        buf   Write data 
 *
 * @return Number of bytes written
 */
writeto(port,addr,buf)

/*
 * @brief read data from I2C.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  i2c device address
 *        buf   The buffer that receives the data. 
 *
 * @return A bytes object with the data read
 */
readfrom(port,addr,nbytes)

/*
 * @brief write data to I2C memory.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  i2c device address
 *        reg   i2c register
 *        buf   Write data  
 *
 * @return None
 */
writeto_mem(port,addr,reg,buf)

/*
 * @brief read data from I2C memory.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  I2C device address
 *        reg   I2C register
 *        nbytes  Receives the data length. 
 *
 * @return A bytes object with the data read.
 */
readfrom_mem(port,addr,reg,nbytes)

/*
 * @brief Select port, after select port, the host can communicate with the slave on this port.
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
 * @param I2CMultiAddr The I2CMultiplexer addr, default address is 0x70.
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
 *        addr  i2c device address
 *        reg   I2C register
 *        buf   Write data  
 */
writeto_mem(port,addr,reg,buf)

/*
 * @brief read data from I2C memory.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  i2c device address
 *        reg   I2C register
 *        nbytes  Receives the data length. 
 *
 * @return Read data
 */
readfrom_mem(port,addr,reg,nbytes)

/*
 * @brief Select port, after select port, the host can communicate with the slave on this port.
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
Arduino |      √       |             |            | 

## History

- data 2018-5-9
- version V0.1


## Credits

- author [Luyuhao  <yuhao.lu@dfrobot.com>]
