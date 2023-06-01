

/******************************************************************/
/***********Código para probar el movimiento de la garra***********/

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
/*****************************************************************/