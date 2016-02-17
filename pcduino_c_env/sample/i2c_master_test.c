#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int deviceHandle;
char buffer[7];

int main (void)
{
  // initialize buffer
  buffer[0] = 0x00;
 
  // open device on /dev/i2c-0
  deviceHandle = open("/dev/i2c-2", O_RDWR);
 
  // connect to arduino as i2c slave
  int deviceI2CAddress = 0x2A;  // (0x2A = 42)
  ioctl(deviceHandle, I2C_SLAVE, deviceI2CAddress);

  buffer[1]=0x01;
  buffer[2]=0x02;
  buffer[3]=0x03;
  buffer[4]=0x04;
  // begin transmission and request acknowledgement
  write(deviceHandle, buffer, 1);
  write(deviceHandle, buffer, 2);
  write(deviceHandle, buffer, 2);
  write(deviceHandle, buffer, 2);
 
  // close connection and return
  close(deviceHandle);
  return 0;
}
