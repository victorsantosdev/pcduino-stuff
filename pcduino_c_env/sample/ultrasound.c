#include <core.h>
const int trig = 2;
const int echo = 3;

long microsecondsToInches(long microseconds)
{
    return (microseconds / 74 / 2);
}

long microsecondsToCentimeters(long microseconds)
{
    return (microseconds / 29 / 2);
}

void setup()
{
    pinMode(echo,INPUT);
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delay(20);
}

void loop()
{
    long duration,inches,cm;
    digitalWrite(trig,HIGH);
    delayMicroseconds(20);
    digitalWrite(trig,LOW);
    duration = pulseIn(echo,HIGH,1000000);
    inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);
    printf("%ld in, %ld cm \n",inches,cm);
    delay(80);
}
