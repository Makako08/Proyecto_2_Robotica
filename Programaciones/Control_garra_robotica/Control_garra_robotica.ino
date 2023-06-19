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

int in1 = 2;
int in2 = 4;
int enA = 8;
int vel = 255;

int mov;
int pot;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(r1, INPUT);
  pinMode(r2, INPUT);
  garra.attach(5);  
  Z.attach(9);
  R.attach(3);
  R.write(90);
  Serial.begin(9600);
}

void loop() {
  //Bloquea el codo y deshabilita la muñeca
  Z.write(90);
  //R.write(deg);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  Serial.print(deg);
  Serial.print("       ");
  Serial.print(analogRead(A0));
  Serial.print("       ");
  Serial.print(analogRead(A2));
  Serial.print("       ");
  Serial.println(pot);
  

  //Gira a la izquierda el servo del hombro
  while(digitalRead(r1) == true && deg != 135){
    deg ++;
    R.write(deg);
    Serial.println(deg);
    delay(40);
  }

  //Gira a la derecha el servo del hombro
  while(digitalRead(r2) == true && deg != 45){
    deg --;
    R.write(deg);
    Serial.println(deg);
    delay(40);
  }
  
//Mueve a la izquierda el codo
  while(analogRead(A2) > 800){
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    Serial.print(deg);
    Serial.print("       ");
    Serial.print(analogRead(A0));
    Serial.print("       ");
    Serial.print(analogRead(A2));
    Serial.print("       ");
    Serial.println(pot);
  }

  //Mueve a la derecha el codo
  while(analogRead(A2) < 200){
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    //Serial.print(deg);
    Serial.print("       ");
    Serial.print(analogRead(A0));
    Serial.print("       ");
    Serial.print(analogRead(A2));
    Serial.print("       ");
    Serial.println(pot);
  }

  //Sube la muñeca
  while(analogRead(A0) > 800){
    Z.write(0);
    R.write(deg);
   Serial.print(deg);
    Serial.print("       ");
    Serial.print(analogRead(A0));
    Serial.print("       ");
    Serial.print(analogRead(A2));
    Serial.print("       ");
    Serial.println(pot);
  }

  //Baja la muñeca
  while(analogRead(A0) < 200){
    Z.write(180);
    //R.write(deg);
   Serial.print(deg);
    Serial.print("       ");
    Serial.print(analogRead(A0));
    Serial.print("       ");
    Serial.print(analogRead(A2));
    Serial.print("       ");
    Serial.println(pot);
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

