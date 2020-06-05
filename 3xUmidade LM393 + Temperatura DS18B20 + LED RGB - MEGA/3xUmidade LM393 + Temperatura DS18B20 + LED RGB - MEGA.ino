#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS A7

#define pino_sinal_analogico A0
#define pino_sinal_analogico1 A1
#define pino_sinal_analogico2 A2

#define pino_led_vermelho A3
#define pino_led_amarelo A4
#define pino_led_verde A5

#define pino_led_vermelho1 A8
#define pino_led_amarelo1 A9
#define pino_led_verde1 A10

#define pino_led_vermelho2 A11
#define pino_led_amarelo2 A12
#define pino_led_verde2 A13

const int red = 4; /* connected to PWM pin 4 */
const int green = 3; /* connected to PWM pin 3 */
const int blue = 2; /* connected to PWM pin 2 */

int r = 255; /* red led value is temporally 255 and it will be the first led to light up */
int b; /* blue led value is temporally 0 */
int g; /* green led value is temporally 0 */
int t = 0; /* "t" (time) 1000 milliseconds, feel free to change it */

int valor_analogico;
int valor_analogico1;
int valor_analogico2;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
 
  Serial.begin(9600);

  pinMode(pino_sinal_analogico, INPUT);
  pinMode(pino_sinal_analogico1, INPUT);
  pinMode(pino_sinal_analogico2, INPUT);

  pinMode(pino_led_vermelho, OUTPUT);
  pinMode(pino_led_amarelo, OUTPUT);
  pinMode(pino_led_verde, OUTPUT);

  pinMode(pino_led_vermelho1, OUTPUT);
  pinMode(pino_led_amarelo1, OUTPUT);
  pinMode(pino_led_verde1, OUTPUT);

  pinMode(pino_led_vermelho2, OUTPUT);
  pinMode(pino_led_amarelo2, OUTPUT);
  pinMode(pino_led_verde2, OUTPUT);

  Serial.println("Arduino Digital Temperature // Serial Monitor Version");

  sensors.begin();
 
}

void loop() {
  

  for (r = 255, b = 0; r >= 0, b < 255; b++, r--)

  {

    leiturasensor();
    leiturasensor1();
    leiturasensor2();

    analogWrite(red, r);
    analogWrite(blue, b);
    delay(t);

  }

  for (b = 255 , g = 0; b >= 0, g < 255; g++, b--)
  {

    leiturasensor();
    leiturasensor1();
    leiturasensor2();

    analogWrite(blue, b);
    analogWrite(green, g);
    delay(t);

  }

  for (g = 255 , r = 0; g >= 0, r < 255; r++, g--)

  {

    leiturasensor();
    leiturasensor1();
    leiturasensor2();

    analogWrite(red, r);
    analogWrite(green, g);
    delay(t);

  }

}

void apagaleds()

{

  digitalWrite(pino_led_vermelho, LOW);

  digitalWrite(pino_led_amarelo, LOW);

  digitalWrite(pino_led_verde, LOW);

}

void apagaleds1()

{

  digitalWrite(pino_led_vermelho1, LOW);

  digitalWrite(pino_led_amarelo1, LOW);

  digitalWrite(pino_led_verde1, LOW);

}

void apagaleds2()

{

  digitalWrite(pino_led_vermelho2, LOW);

  digitalWrite(pino_led_amarelo2, LOW);

  digitalWrite(pino_led_verde2, LOW);

}


void leiturasensor() {

  sensors.requestTemperatures(); 

  Serial.print("Temperatura é: ");

  Serial.println(sensors.getTempCByIndex(0));

  valor_analogico = analogRead(pino_sinal_analogico);

  if (valor_analogico > 0 && valor_analogico < 350)

  {

    apagaleds();

    digitalWrite(pino_led_verde, HIGH);

  }

  if (valor_analogico > 350 && valor_analogico < 650)

  {

    apagaleds();

    digitalWrite(pino_led_amarelo, HIGH);

  }

  if (valor_analogico > 650 && valor_analogico < 1024)

  {

    apagaleds();

    digitalWrite(pino_led_vermelho, HIGH);

  }

}

void leiturasensor1() {

  sensors.requestTemperatures(); 

  Serial.print("Temperatura é: ");

  Serial.println(sensors.getTempCByIndex(0));

  valor_analogico1 = analogRead(pino_sinal_analogico1);

  if (valor_analogico1 > 0 && valor_analogico1 < 350)

  {

    apagaleds1();

    digitalWrite(pino_led_verde1, HIGH);

  }

  if (valor_analogico1 > 350 && valor_analogico1 < 650)

  {

    apagaleds1();

    digitalWrite(pino_led_amarelo1, HIGH);

  }

  if (valor_analogico1 > 650 && valor_analogico1 < 1024)

  {

    apagaleds1();

    digitalWrite(pino_led_vermelho1, HIGH);

  }

}

void leiturasensor2() {

  sensors.requestTemperatures(); 

  Serial.print("Temperatura é: ");

  Serial.println(sensors.getTempCByIndex(0));

  valor_analogico2 = analogRead(pino_sinal_analogico2);

  if (valor_analogico2 > 0 && valor_analogico2 < 350)

  {

    apagaleds2();

    digitalWrite(pino_led_verde2, HIGH);

  }

  if (valor_analogico2 > 350 && valor_analogico2 < 650)

  {

    apagaleds2();

    digitalWrite(pino_led_amarelo2, HIGH);

  }

  if (valor_analogico2 > 650 && valor_analogico2 < 1024)

  {

    apagaleds2();

    digitalWrite(pino_led_vermelho2, HIGH);

  }

}
