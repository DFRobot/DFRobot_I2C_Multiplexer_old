# -*- coding: utf-8 -*-
import time
import sys
import smbus

class I2CMultiplexer:
  def __init__(self,addr):
    self.i2c = smbus.SMBus(1)
    self.addr = addr
  
  def scan(self,port):
    buf = []
    self.selectPort(port)
    for addr in range(0,128):
      if(addr == self.addr):
        continue
      try:
        self.i2c.write_byte(addr,0)
        buf.append(addr)
      except:
        pass
    return buf
  
  def selectPort(self,port):
    if(port > 7):
      return
    data = 1<<port
    self.i2c.write_byte(self.addr,data)
    
  def writeto_mem(self,port,addr,reg,buf):
    self.selectPort(port)
    l = len(buf)
    for i in range(0,l):
      self.i2c.write_byte_data(addr,reg,buf[i])
    time.sleep(0.1)
    return l
    
  def readfrom_mem(self,port,addr,reg,nbytes):
    self.selectPort(port)
    return self.i2c.read_i2c_block_data(addr,reg,nbytes)

