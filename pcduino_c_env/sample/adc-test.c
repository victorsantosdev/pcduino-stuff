/*
* ADC test program
*/
#include <core.h>
int adc_id2 = 2;
int adc_id3 = 3;
int delay_us = 100000;
int adc_id = 0;
void setup()
{/*
    if ( argc != 2 )
    {
        printf("Usage %s ADC_ID(0/1/2/3/4/5/6/7/8/9/10/11)\n", argv[0]);
        printf("Default will get ADC0 value\n");  
    }
    
    if(argc==2) 
        adc_id = atoi(argv[1]);
*/
}

void loop()
{
    int value1= analogRead(adc_id2); // get adc value
    int value2= analogRead(adc_id3); // get adc value
    float voltage1= value1*3.0/4095;//ajuste de fundo de escala do ADC 3300 (3V3) 4095 - 12 bits ADC A2to A5
    float voltage2= value2*3.0/4095;//ajuste de fundo de escala do ADC 3300 (3V3) 4095 - 12 bits ADC A2to A5
    //voltage = voltage - 0.2; //ajuste de erro do ADC
    printf("ADC%d= %d\tvoltage=%.2f\n",adc_id2, value1,voltage1);
    printf("ADC%d= %d\tvoltage=%.2f\n",adc_id3, value2,voltage2);

    delayMicroseconds(delay_us);  
}
