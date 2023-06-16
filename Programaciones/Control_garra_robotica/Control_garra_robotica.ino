#include <Servo.h>
Servo R;
Servo Y;
Servo garra;

int deg = 90;

int r1 = 13;
int r2 = 12;

int in1 = 11;
int in2 = 10;

int mov;
int pot;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  pinMode(r1, INPUT);
  pinMode(r2, INPUT);
  garra.atach(5)  
  Y.attach(6);
  R.attach(9);
}

void loop() {
  //Bloquea el codo y deshabilita la muñeca
  Y.write(90);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);

  //Gira a la izquierda el servo del hombro
  while(digitalRead(r1) == true && deg <= 135){
    R.write(deg);
    deg ++;
  }

  //Gira a la derecha el servo del hombro
  while(digitalRead(r2) == true && deg >= 45){
    R.write(deg);
    deg --;
  }
  
  //Mueve a la izquierda el codo
  while(analogRead(A1) >= 240){
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
  }

  //Mueve a la derecha el codo
  while(analogRead(A1) <= 50){
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
  }

  //Sube la muñeca
  while(analogRead(A0) >= 240){
    Y.write(0);
  }

  //Baja la muñeca
  while(analogRead(A0) <= 50){
    Y.write(180);
  }

  //Control para abrirb y cerrar la garra
  pot = analogRead(A3);
  mov = map(pot, 0, 1023, 35, 110);
  garra.write(mov);

}

