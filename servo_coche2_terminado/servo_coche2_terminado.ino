#include <Servo.h>
Servo servoMain;
Servo servoMain2;

const int boton8 = 8; // Un botón en el pin 8
const int boton9 = 9; // Otro botón en el pin 9
const int pwmPin = 3; // El servo en el pin 3
const int pwmPin2 = 5; // El otro servo en el pin 5
const int boton10 = 10; // Un boton en  el pin 10
const int boton11 = 11; //Otro boton en el pin 11
// variables
int buttonState8 = 0;
int buttonState9 = 0;
int grados;
int buttonState10 = 0;
int buttonState11 = 0;
int motor;
void setup() {
  Serial.begin(9600);
  pinMode(boton8, INPUT);
  pinMode(boton9, INPUT);
  pinMode (pwmPin, OUTPUT);
  servoMain.attach(pwmPin);
  Serial.begin(9600);
  pinMode(boton10, INPUT);
  pinMode(boton11, INPUT);
  pinMode (pwmPin2, OUTPUT);
  servoMain2.attach(pwmPin2);
}

void loop() {

  buttonState8 = digitalRead(boton8);
  buttonState9 = digitalRead(boton9);
  buttonState10 = digitalRead(boton10);
  buttonState11 = digitalRead(boton11);
  if (buttonState8 == HIGH)
  {
    grados = grados - 10;
    if (grados < 0)
    {
      grados = 0;
    }
    servoMain.write(grados);
    Serial.println(grados);
  }

  if (buttonState9 == HIGH) 
  {
    grados = grados + 10;
    if (grados > 180) 
    {
      grados = 180;
    }
    servoMain.write(grados);
    Serial.println(grados);
  }

  delay(100);

  if (buttonState10 == HIGH) {
    motor = motor - 10;
    if (motor < 0) {
      motor = 0;
    }
    servoMain2.write(motor);
    Serial.println(motor);
  }

  if (buttonState11 == HIGH) {
    motor = motor + 10;
    if (motor > 180) {
      motor = 180;
    }
    servoMain2.write(motor);
    Serial.println(motor);
  }
}
