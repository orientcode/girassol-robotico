#include <Servo.h>

Servo servoY;
Servo servoX;

#define quadrante1 A1
#define quadrante2 A2
#define quadrante3 A3
#define quadrante4 A4

#define VALOR 800

int anguloX = 100;
int anguloY = 180;

void setup() {
  pinMode(quadrante1, INPUT);
  pinMode(quadrante2, INPUT);
  pinMode(quadrante3, INPUT);
  pinMode(quadrante4, INPUT);
  servoY.attach(9);
  servoX.attach(8);
  servoX.write(anguloX);
  servoY.write(anguloY);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  int valorQuadrante1 = analogRead(quadrante1);
  int valorQuadrante2 = analogRead(quadrante2);
  int valorQuadrante3 = analogRead(quadrante3);
  int valorQuadrante4 = analogRead(quadrante4);

  Serial.println(valorQuadrante1);
  
  delay(100);
}
