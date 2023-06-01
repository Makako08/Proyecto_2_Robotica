
/******************************************************************/
/********************Código para mover la garra********************/

#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3; 

float x;
void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
}

void loop() {
  x = map(analogRead(A0), 0, 1023, 35, 90);
  
  servo1.write(x);
  servo2.write(x);
  servo3.write(x);

}

/******************************************************************/







/******************************************************************/
/***********Código para probar el movimiento de la garra***********/
/*
#include <Servo.h>
Servo myservo; 


void setup() {
  myservo.attach(3);  
}

void loop() {
for (pos = 35; pos <= 90; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(10);                       
  }
  for (pos = 90; pos >= 35; pos -= 1) { 
    myservo.write(pos);              
    delay(10); 
  }
}
*/
/*****************************************************************/