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
int vel = 210;

int mov;
int pot;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(r1, INPUT);
  pinMode(r2, INPUT);
  garra.attach(5);  
  Z.attach(6);
  R.attach(9);
  R.write(deg);
}

void loop() {
  //Bloquea el codo y deshabilita la muñeca
  Z.write(90);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);

  //Gira a la izquierda el servo del hombro
  if(digitalRead(r1) == true && deg != 135){
    deg ++;
    R.write(deg);
    delay(25);
  }

  //Gira a la derecha el servo del hombro
  if(digitalRead(r2) == true && deg != 45){
    deg --;
    R.write(deg);
    delay(25);
  }
  
  //Mueve a la izquierda el codo
  while(analogRead(A1) >= 240){
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    analogWrite(enA, vel);
  }

  //Mueve a la derecha el codo
  while(analogRead(A1) <= 50){
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    analogWrite(enA, vel);
  }

  //Sube la muñeca
  while(analogRead(A0) >= 240){
    Z.write(0);
  }

  //Baja la muñeca
  while(analogRead(A0) <= 50){
    Z.write(180);
  }

  //Control para abrir y cerrar la garra
  pot = analogRead(A2);
  mov = map(pot, 0, 1023, 35, 110);
  garra.write(mov);

}

