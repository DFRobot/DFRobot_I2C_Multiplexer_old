# I2C Multiplexer Library for Arduino/ESP32/RaspberrayPi
This is a Library for I2C Multiplexer,the function is to solve multiple I2C device address conflicts.
这里放svg图
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
* 这是I2C Multiplexer的库,I2C Multiplexer可以解决一个I2C接口上接多个相同地址设备冲突的问题.
* I2C Multiplexer有X个I2C子端口，调用selectPort(n)函数选择端口后,主设备将会扫描到子端口n上连接的I2C设备,与子端口n上连接的I2C设备通信. 
* I2C Multiplexer上的拨码开关可以改变I2C Multiplexer的地址.
* I2C Multiplexer的子端口上也可以接多个设备

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
  dev.selectPort(1);                    //选择端口后, 主机将会扫描到这个端口上的从机
  Wire.beginTransmission(I2CAddr);
  Wire.write(0x00); 
  Wire.endTransmission();
  Wire.requestFrom(I2CAddr, 4);
  while (Wire.available()){
    Serial.println(Wire.read());
  }
}
```

### 用于SSD1306模块
``` C++
#include "DFRobot_SSD1306_I2C.h"
#include "DFRobot_I2CMultiplexer.h"
#include <Wire.h>

/*创建一个OLED对象，地址为0x3c*/
DFRobot_SSD1306_I2C OLED(0x3c);

/*创建I2C Multiplexer对象, 0x70是I2C Multiplexer的地址*/
DFRobot_I2CMultiplexer I2CMulti(0x70);


void setup(void){
  /*让0端口上的OLED显示字符*/
  I2CMulti.selectPort(0);       //选择端口
  OLED.begin();                 //OLED初始化
  OLED.setTextColor(1);
  OLED.setTextSize(2);
  
  OLED.setCursor(0,0);          //设置字符坐标
  OLED.print("device A");       //显示字符
  OLED.setCursor(0,30);
  OLED.print("addr:0x3C");

  /*让1端口上的OLED显示字符*/
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
 * @param addr The I2CMultiplexer addr
 */
DFRobot_I2CMultiplexer(uint8_t addr);

/*
 * @brief Scan I2C on the port
 *
 * @param port The port which to scan
 *
 * @return I2C addr
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
 *
 * @return 0 success else false
 */
uint8_t write(uint8_t port,uint8_t addr, uint8_t reg,uint8_t* buf, uint8_t len);

/*
 * @brief 选择端口,选择端口后,主设备将扫描到该端口上的从设备
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
 *        addr  7bit i2c device address
 *        buf   Write data 
 *
 * @return Number of bytes written
 */
writeto(port,addr,buf)

/*
 * @brief read data from I2C.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  7bit i2c device address
 *        buf   The buffer that receives the data. 
 *
 * @return A bytes object with the data read
 */
readfrom(port,addr,nbytes)

/*
 * @brief write data to I2C memory.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  7bit i2c device address
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
 *        addr  7bit I2C device address
 *        reg   I2C register
 *        nbytes  Receives the data length. 
 *
 * @return A bytes object with the data read.
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
 *        reg   I2C register
 *        buf   Write data  
 */
writeto_mem(port,addr,reg,buf)

/*
 * @brief read data from I2C memory.
 *
 * @param port  I2CMultiplexer port(0~7)
 *        addr  7bit i2c device address
 *        reg   I2C register
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
