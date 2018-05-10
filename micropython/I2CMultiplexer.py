from machine import Pin,I2C
import time

class I2CMultiplexer:
  def __init__(self,I2CMultiAddr):
    self.i2c = I2C(scl=Pin(22), sda=Pin(21), freq=10000)
    self.addr = I2CMultiAddr
  
  def scan(self,port):
    buf = []
    i = 0
    self.selectPort(port)
    for addr in range(0,128):
      if(addr == self.addr):
        continue
      try:
        if(self.i2c.writeto(addr,b'0')):
          buf.append(addr)
      except:
        pass
    return buf
  
  def selectPort(self,port):
    if(port > 7):
      return
    buf = bytearray(1)
    buf[0] = 1<<port
    self.i2c.start()
    self.i2c.writeto(self.addr,buf)
    self.i2c.stop()
  
  def writeto(self,port,addr,buf):
    self.selectPort(port)
    return self.i2c.writeto(addr,buf)
  
  def readfrom(self,port,addr,nbytes):
    self.selectPort(port)
    return self.i2c.readfrom(addr,nbytes)
    
  def writeto_mem(self,port,addr,reg,buf):
    self.selectPort(port)
    return self.i2c.writeto_mem(addr,reg,buf)
    
  def readfrom_mem(self,port,addr,reg,nbytes):
    self.selectPort(port)
    b = bytearray(1)
    b[0] = 0
    self.i2c.write(b)
    return self.i2c.readfrom_mem(addr,reg,nbytes)