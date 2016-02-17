#include <core.h>
#define BRAKEVCC 0
#define CW 1
#define CCW 2
#define BRAKEGND 3
#define CS_THRESHOLD 100   // Definição da corrente de segurança (Consulte: "1.3) Monster Shield Exemplo").

int inApin[2] = {7, 4}; // INA: Sentido Horário Motor0 e Motor1 (Consulte:"1.2) Hardware Monster Motor Shield").
int inBpin[2] = {8, 9}; // INB: Sentido Anti-Horário Motor0 e Motor1 (Consulte: "1.2) Hardware Monster Motor Shield").
int pwmpin[2] = {5, 6};            // Entrada do PWM
int cspin[2] = {2, 3};              // Entrada do Sensor de Corrente

int statpin = 13;
int i=0;
int leitura_adc_m0=0;
int leitura_corrente_m1=0;

void motorOff(int motor)     //Função para desligar o motor se o mesmo travar
{

    for (i=0; i<2; i++)
    {
        digitalWrite(inApin[i], LOW);
        digitalWrite(inBpin[i], LOW);
    }
    analogWrite(pwmpin[motor], 0);
    i=0;
    digitalWrite(13, HIGH);
    Serial.println("Motor Travado");
    delay(1000);
}

void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)         //Função que controla as variáveis: motor(0 ou 1), sentido (cw ou ccw) e pwm (entra 0 e 255);
{
    if (motor <= 1)
    {
        if (direct <=4)
        {
            if (direct <=1)
                digitalWrite(inApin[motor], HIGH);
            else
                digitalWrite(inApin[motor], LOW);

            if ((direct==0)||(direct==2))
                digitalWrite(inBpin[motor], HIGH);
            else
                digitalWrite(inBpin[motor], LOW);

            analogWrite(pwmpin[motor], pwm);
        }
    }
}


void setup()                         // Faz as configuração para a utilização das funções no Sketch
{
    Serial.begin(9600);              // Iniciar a serial para fazer o monitoramento
    pinMode(statpin, OUTPUT);

    for (i=0; i<2; i++)
    {
        pinMode(inApin[i], OUTPUT);
        pinMode(inBpin[i], OUTPUT);
        pinMode(pwmpin[i], OUTPUT);
    }
    for (i=0; i<2; i++)
    {
        digitalWrite(inApin[i], LOW);
        digitalWrite(inBpin[i], LOW);
    }
}

void loop()                          // Programa roda dentro do loop
{
    //while(i<25)
    //    {
    //    motorGo(0, CW, i);             // Aumento do o PWM do motor até 255
    //    motorGo(1, CW, i);             // Aumento do o PWM do motor até 255
    //    delay(50);                          // Se o motor travar ele desliga o motor e
    //    i++;                                  // Reinicia o processo de aumento do PWM
    //    leitura_corrente_m0 = analogRead(cspin[0]);
    //    Serial.println("leitura de corrente motor0: ");
    //    Serial.println(leitura_corrente_m0);
    //    if (leitura_corrente_m0 > CS_THRESHOLD)
    //    motorOff(0);
    //    Serial.println("leitura de corrente motor1: ");
    //    leitura_corrente_m1 = analogRead(cspin[1]);
    //    if (leitura_corrente_m1 > CS_THRESHOLD)
    //    motorOff(1);
    //    Serial.println(i);
    //    digitalWrite(statpin, LOW);
    //    }
    //i=1;
    //while(i!=0)
    //{                                      // Mantém o PWM em 255 (Velocidade Máxima do Motor)
    motorGo(0, CW, 30);       // Se o motor travar ele desliga o motor e
    motorGo(1, CW, 30);       // Se o motor travar ele desliga o motor e
    leitura_adc_m0 = analogRead(cspin[0]);
    Serial.println("leitura de corrente motor0: ");
    float voltage_m0= (leitura_adc_m0*3.0)/4096;//ajuste de fundo de escala do ADC 3300 (3V0)    4095 - 12 bits ADC A2to A5
    printf("ADC%d= %d\tvoltage=%.4f\n",cspin[0], leitura_adc_m0,voltage_m0);
    float valor_corrente_m0 = (voltage_m0*11370)/1500; //11370 valor tipico no datasheet, 1500 eh o valor de 1.5k do resistor de leitura de corrente R6
    printf("valor de corrente lido(mA): %3.3f\n", valor_corrente_m0);
    delay(2000);
    //if (leitura_adc_m0 > CS_THRESHOLD)              // Reinicia o processo de aumento do PWM
    //    motorOff(0);
    /*
    Serial.println("leitura de corrente motor1: ");
    leitura_corrente_m1 = analogRead(cspin[1]);
    float voltage_m1= leitura_corrente_m1*3.0/4095.0;//ajuste de fundo de escala do ADC 3300 (3V3)    4095 - 12 bits ADC A2to A5
    //Serial.println(leitura_corrente_m1);
    printf("ADC%d= %d\tvoltage=%1.3f\n",cspin[1], leitura_corrente_m1,voltage_m1);
    if (leitura_corrente_m1 > CS_THRESHOLD)              // Reinicia o processo de aumento do PWM
        motorOff(1);
    //}
    */
}
