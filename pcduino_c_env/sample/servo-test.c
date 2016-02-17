/*
 * ADC test program
 */
#include <core.h>

int servopin=3;//Define servo PWM control as digital 3
int myangle;//define variable angle
int pulsewidth;//define variable pulse width
int val;
void servopulse(int servopin,int myangle)//define a pulse function
{
    pulsewidth=(myangle*11)+500;//translate angle to a pulse width value between 500-2480
    digitalWrite(servopin,HIGH);//pull the interface signal level to high
    delayMicroseconds(pulsewidth);//delay in microseconds
    digitalWrite(servopin,LOW);//pull the interface signal level to low
    delay(20-pulsewidth/1000);
}
void setup()
{
    pinMode(servopin,OUTPUT);//set the interface pin as output
}
void loop()//translate the number 0-9 to angle between 0 degree to 180 degree, and let LED blink the same times
{
    //val=4;
    printf("Enter with a angle value:\n");
    scanf("%d", &val);
    //val=val*(180/9);//translate number to angle
    for(int i=0;i<=50;i++)//wait enough time so that the servo can rotate to the specified angle
    {
        servopulse(servopin,val);//call the pulse function
    }
    for(int i=0;i<=50;i++)//wait enough time so that the servo can rotate to the specified angle
    {
        servopulse(servopin,0);//call the pulse function
    }
}
