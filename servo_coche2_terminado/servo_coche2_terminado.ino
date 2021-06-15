#include <Servo.h>//incluimos libreria
Servo servoMain;//declaramos el primer servo
Servo servoMain2;//declaramos el segundo servo

const int boton8 = 8; // Un botón en el pin 8
const int boton9 = 9; // Otro botón en el pin 9
const int pwmPin = 3; // El servo en el pin 3
const int pwmPin2 = 5; // El otro servo en el pin 5
const int boton10 = 10; // Un boton en  el pin 10
const int boton11 = 11; //Otro boton en el pin 11.
// variables
int buttonState8 = 0;//boton para adelante
int buttonState9 = 0;//boton marcha atras
int grados; //variable del primer servo
int buttonState10 = 0;//boton 2 para adelante
int buttonState11 = 0;//boton 2 marcha atras
int motor;// variable del segundo servo
void setup() {
  Serial.begin(9600);// abre puerto
  pinMode(boton8, INPUT);// declaramos que el boton8 es pin de entrada
  pinMode(boton9, INPUT);// declaramos que el boton9 es pin de entrada
  pinMode (pwmPin, OUTPUT);// declaramos que el pwmPin es pin de salida
  servoMain.attach(pwmPin);// declaramos el servo y su pin de señal
  Serial.begin(9600);// abre puerto
  pinMode(boton10, INPUT);// declaramos que el boton10 es pin de entrada
  pinMode(boton11, INPUT);// declaramos que el boton11 es pin de entrada
  pinMode (pwmPin2, OUTPUT);// declaramos que el pwmPin2 es pin de salida
  servoMain2.attach(pwmPin2);// declaramos el servo y su pin de señal
}

void loop() {

  buttonState8 = digitalRead(boton8);//las variable lee el boton8 
  buttonState9 = digitalRead(boton9);// las variables lee el boton9
  buttonState10 = digitalRead(boton10);//las variablelee el boton10
  buttonState11 = digitalRead(boton11);//las varibles del boton lee el boton11
  if (buttonState8 == HIGH)// si el boton8 es igual a nivel alto
  {
    grados = grados - 10;// resta -10
    if (grados < 0)
    {
      grados = 0;
    }
    servoMain.write(grados);//escribe servoMain en grados
    Serial.println(grados);//escribe el caracter de grados
  }

  if (buttonState9 == HIGH)// si el boton9 es igual a nivel alto
  {
    grados = grados + 10;// suma 10
    if (grados > 180) 
    {
      grados = 180;
    }
    servoMain.write(grados);//escribe servoMain en grados
    Serial.println(grados);//escribe el caracter de grados
  }

  delay(100);

  if (buttonState10 == HIGH) {// si el boton10 es igual a nivel alto
    motor = motor - 10;//resta -10
    if (motor < 0) {
      motor = 0;
    }
    servoMain2.write(motor);//escribe servoMain2 en motor
    Serial.println(motor);//escribe el caracter de motor
  }

  if (buttonState11 == HIGH) {// si el boton11 es igual a nivel alto
    motor = motor + 10;
    if (motor > 180) {
      motor = 180;
    }
    servoMain2.write(motor);//escribe servoMain2 en motor
    Serial.println(motor);//escribe el caracter de motor
  }
}
