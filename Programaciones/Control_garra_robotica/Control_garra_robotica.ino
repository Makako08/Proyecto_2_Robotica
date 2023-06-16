#include <Servo.h>
Servo R;
Servo Y;

int deg = 90;

int r1 = 13;
int r2 = 12;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(r1, INPUT);
  pinMode(r2, INPUT);
  R.attach(9);
  Y.attach(3);
}

void loop() {
  //Deja quieto 
  Y.write(90);
  while(digitalRead(r1) == true && deg <= 135){
    R.write(deg);
    cont ++;
  }
  while(digitalRead(r2) == true && deg >= 45){
    R.write(deg);
    cont --;
  }

  while(analogRead(A0) >= 240){
    Y.write(0);
  }
  while(analogRead(A0) <= 50){
    Y.write(180)
  }

}

