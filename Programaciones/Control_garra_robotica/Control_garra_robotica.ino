/*
vrx y vry en A0 y a A1
Botones a pines 13 y 12
Potenciómetro en A2
ENA al pin 8
IN1 del shield al pin 11
IN2 del shield al pin 3
Control Servo 360 a pin 6
Control Servo 180 a pin 9
*/

#include <Servo.h>
Servo R;
Servo Z;
Servo garra;

int deg = 90;

int r1 = 13;
int r2 = 12;

int in1 = 11;
int in2 = 3;
int enA = 8;
int vel = 255;

int mov;
int pot;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(r1, INPUT);
  pinMode(r2, INPUT);
  garra.attach(5);  
  Z.attach(9);
  R.attach(6);
  R.write(deg);
}

void loop() {
  //Bloquea el codo y deshabilita la muñeca
  Z.write(90);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);

  //Gira a la izquierda el servo del hombro
  while(digitalRead(r1) == true && deg != 135){
    deg ++;
    R.write(deg);
    delay(60);
  }

  //Gira a la derecha el servo del hombro
  while(digitalRead(r2) == true && deg != 45){
    deg --;
    R.write(deg);
    delay(60);
  }
  
//Mueve a la izquierda el codo
  while(analogRead(A1) > 800){
    analogWrite(in1, vel);
    digitalWrite(in2, 0);
    digitalWrite(enA, HIGH);
  }

  //Mueve a la derecha el codo
  while(analogRead(A1) < 200){
    digitalWrite(in1, 0);
    analogWrite(in2, vel);
    digitalWrite(enA, HIGH);
  }

  //Sube la muñeca
  while(analogRead(A0) > 800){
    Z.write(0);
  }

  //Baja la muñeca
  while(analogRead(A0) < 200){
    Z.write(180);
  }

  //Control para abrir y cerrar la garra
  pot = analogRead(A3);
  //mov = map(pot, 0, 1023, 35, 110);
  if (pot < 500){
    garra.write(35);
  }
  if (pot > 500){
    garra.write(110);
  }
}

