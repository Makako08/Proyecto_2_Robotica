/******************************************************************/
/********************Código para mover la garra********************/
/*
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver();

unsigned int pos0 = 132;
unsigned int pos180 = 530;

int grado = 70;
int tiempo = 500;
float x;
int pot;

void setup(){
  servos.begin();
  servos.setPWMFreq(50);
}

void setServo(uint8_t n_servo, int angulo){
  int duty;
  duty = map(angulo, 0, 180, pos0, pos180);
  
  servos.setPWM(n_servo, 0, duty);
}

void loop(){
  pot = analogRead(A0);
  x = map(pot, 0, 1023, 0, 70);
  setServo(13, x);
  delay(15);
  setServo(14, (x-10));
  delay(15);
  setServo(15, (x-10));
  delay(15); 
}
*/
/******************************************************************/
/***********Código para probar el movimiento de la garra***********/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver();

unsigned int pos0 = 172;
unsigned int pos180 = 530;

int grado = 70;

int tiempo = 500;
void setup(){
   servos.begin();
   servos.setPWMFreq(50);
}

void setServo(uint8_t n_servo, int angulo){
  int duty;
  duty = map(angulo, 0, 180, pos0, pos180);
  
  servos.setPWM(n_servo, 0, duty);
}

void loop(){
  //Aquí solo se miden los límites de la garra
  setServo(13, grado);
  setServo(14, (grado-10));
  setServo(15, (grado-10));

  for (int pos = 15; pos <= 70; pos += 1) { 
    setServo(13, pos);
    setServo(14, (pos-10));
    setServo(15, (pos-10));              
    delay(20);                       
  }
  for (int pos = 70; pos >= 15; pos -= 1) { 
    setServo(13, pos);
    setServo(14, (pos-10));
    setServo(15, (pos-10));             
    delay(20);
  }

}
/*****************************************************************/