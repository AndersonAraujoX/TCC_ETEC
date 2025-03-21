//Programa: Sensor TCS3200 e led RGB

//Autor: FILIPEFLOP

 

//Pinos de conexao do modulo

int s0 = 8;

int s1 = 9;

int s2 = 12;

int s3 = 11;

int out = 10;

 

//Pinos do led RGB

int pinoledverm = 2;

int pinoledverd = 3;

int pinoledazul = 4;

 
#include <Servo.h>

 

#define SERVO 6 // Porta Digital 6 PWM

Servo se1; // Variável Servo
Servo se2;
int pos; // Posição Servo

//Variaveis cores

int red = 0;

int green = 0;

int blue = 0;

 

void setup()

{

  pinMode(s0, OUTPUT);

  pinMode(s1, OUTPUT);

  pinMode(s2, OUTPUT);

  pinMode(s3, OUTPUT);

  pinMode(out, INPUT);

  pinMode(pinoledverm, OUTPUT);

  pinMode(pinoledverd, OUTPUT);

  pinMode(pinoledazul, OUTPUT);

  Serial.begin(9600);

  digitalWrite(s0, HIGH);

  digitalWrite(s1, LOW);

  se1.attach(SERVO);
    
  Serial.begin(9600);

  se1.write(0); // Inicia motor posição zero

}

 

void loop()

{

  //Detecta a cor

  color();

  //Mostra valores no serial monitor

  Serial.print("Vermelho :");

  Serial.print(red, DEC);

  Serial.print(" Verde : ");

  Serial.print(green, DEC);

  Serial.print(" Azul : ");

  Serial.print(blue, DEC);

  Serial.println();

 

  //Verifica se a cor vermelha foi detectada

  if ( blue > 200&& green > 200 && red > 200)

  {

    Serial.println("Vermelho");

s1.write (45);

delay (1000);

s1.write (0);

    digitalWrite(pinoledverm, LOW); //Acende o led vermelho

    digitalWrite(pinoledverd, HIGH);

    digitalWrite(pinoledazul, HIGH);

  }

 

  //Verifica se a cor azul foi detectada

  else if (red < 200&& blue < 200 && green < 200)

  {

    Serial.println("Azul");

    digitalWrite(pinoledverm, HIGH);

    digitalWrite(pinoledverd, HIGH);

    digitalWrite(pinoledazul, LOW); //Acende o led azul

  }

 

  //Verifica se a cor verde foi detectada

  else if (green < red && green < blue)

  {

    Serial.println("Verde");

    digitalWrite(pinoledverm, HIGH);

    digitalWrite(pinoledverd, LOW); //Acende o led verde

    digitalWrite(pinoledazul, HIGH);

  }

  Serial.println();

 

  //Delay para apagar os leds e reiniciar o processo

  delay(50);

  digitalWrite(pinoledverm, HIGH);

  digitalWrite(pinoledverd, HIGH);

  digitalWrite(pinoledazul, HIGH);

}

 

void color()

{

  //Rotina que le o valor das cores

  digitalWrite(s2, LOW);

  digitalWrite(s3, LOW);

  //count OUT, pRed, RED

  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  digitalWrite(s3, HIGH);

  //count OUT, pBLUE, BLUE

  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  digitalWrite(s2, HIGH);

  //count OUT, pGreen, GREEN

  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

}

