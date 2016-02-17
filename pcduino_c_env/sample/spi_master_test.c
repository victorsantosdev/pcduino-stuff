 
#include <core.h>  // for pcDuino
#include <SPI.h>
int ss = 10;
int del = 1000;
 
void setup()
{
  SPI.begin();
  SPI.setDataMode(SPI_MODE3);
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  pinMode(ss, OUTPUT);
  digitalWrite(ss, HIGH);
}
 
void setValue(int value)
{
  digitalWrite(ss, LOW);
  SPI.transfer(0, SPI_CONTINUE);
  SPI.transfer(value, SPI_LAST);
  digitalWrite(ss, HIGH);
}
 
void loop()
{
  setValue(255);
  delay(del);
  setValue(223);
  delay(del);
  setValue(191);
  delay(del);
  setValue(159);
  delay(del);
  setValue(127);
  delay(del);
  setValue(95);
  delay(del);
  setValue(63);
  delay(del);
  setValue(31);
  delay(del);
  setValue(0);
  delay(del);
}
