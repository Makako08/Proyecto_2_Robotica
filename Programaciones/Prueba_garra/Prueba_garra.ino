/******************************************************************/
/********************Código para mover la garra********************/

#include <Servo.h>
Servo servo1;
Servo servo2;
//Servo servo3; 

int x;
int pot;

void setup() {
  pinMode(A2, INPUT);
  servo1.attach(5);
}

void loop() {
  pot = analogRead(A2);
  x = map(pot, 0, 1023, 35, 110);
  
  servo1.write(x);
  
}

/******************************************************************/







/******************************************************************/
/***********Código para probar el movimiento de la garra***********/
/*
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3; 
void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
}

void loop() {

for (int pos = 55; pos <= 115; pos += 1) { 
  servo1.write(pos);
  servo2.write(pos);
  servo3.write(pos);              
  delay(10);                       
  }

for (int pos = 115; pos >= 55; pos -= 1) { 
  servo1.write(pos);
  servo2.write(pos);
  servo3.write(pos);
  delay(10);
  }

}
*/
/*****************************************************************/