 /*!
  * file I2CReadWrite.ino
  * 
  * 将I2C设备插到I2CMultiplexer的0端口上,然后连接I2CMultiplexer和Arduino,下载此示例
  * @n 打开串口可以看到读取的信息.
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V0.1
  * date  2018-5-10
  */

#include <DFRobot_I2CMultiplexer.h>

/*创建一个I2CMultiplexer对象,0x70是I2C Multiplexer的地址*/
DFRobot_I2CMultiplexer I2CMultiplexer(0x70);

/*I2C设备在端口0上*/
uint8_t port = 0;

/*I2C的地址为24*/
uint8_t i2c_addr = 24;

/*I2C设备的寄存器地址*/
reg = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  uint8_t buf[3] = {0}; 
  
  /*从0端口的I2C设备读取3个字节到buf中*/
  if(I2CMultiplexer.read(port,i2c_addr,reg,buf,3) > 0){
    Serial.println((int)buf[0],HEX);  
    Serial.println((int)buf[1],HEX);
    Serial.println((int)buf[2],HEX);
  }
  
  uint8_t data[2] = {111,107};
  
  /*将data写入端口0上的I2C设备,data的长度为3*/
  if (!I2CMultiplexer.write(port,i2c_addr,reg, data, 2)) {
     Serial.println("write OK");
  }
  delay(1000);
}