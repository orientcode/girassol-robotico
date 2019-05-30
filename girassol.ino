#include <Servo.h>

Servo servoY;
Servo servoX;

#define quadrante1 A4
#define quadrante2 A3
#define quadrante3 A2
#define quadrante4 A1

#define VALOR 200

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

  Serial.print("Quadrante 01: ");
  Serial.println(valorQuadrante1);
  Serial.print("Quadrante 02: ");
  Serial.println(valorQuadrante2);
  Serial.print("Quadrante 03: ");
  Serial.println(valorQuadrante3);
  Serial.print("Quadrante 04: ");
  Serial.println(valorQuadrante4);
  Serial.println("--------------");
  Serial.print("Angulo X: ");
  Serial.println(anguloX);
  Serial.print("Angulo Y: ");
  Serial.println(anguloY);
  Serial.println("---------------------------------");
  
  if (anguloX >= 176) anguloX = 176;
  if (anguloX <= 10) anguloX = 10;
  if (anguloY >= 176) anguloY = 176;
  if (anguloY <= 10) anguloY = 10;
  
  if ((valorQuadrante1 + valorQuadrante2 + valorQuadrante3 + valorQuadrante4) / 4 > VALOR) {
    if ((valorQuadrante1 + valorQuadrante2) > (valorQuadrante3 + valorQuadrante4)) {
      anguloX -= 2;
    } else {
      anguloX += 2; 
    } 
    if ((valorQuadrante1 + valorQuadrante4) > (valorQuadrante2 + valorQuadrante3)) {
      anguloY -= 2;
    } else {
      anguloY += 2;
    }
  }
  else {
    anguloX = 100;
    anguloY = 176;
    delay(100);
  }
  servoX.write(anguloX);
  servoY.write(anguloY);
  delay(20);
}
