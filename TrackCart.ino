#include <Servo.h>
#include <ServoInput.h>

const int motor1Pin = 13;
const int motor2Pin = 12;
Servo motor1;
Servo motor2;
ServoInputPin<3> controller;

void setup() {
	controller.attach();
  motor1.attach(motor1Pin);
  motor2.attach(motor2Pin);

  Serial.begin(9600);
}

void loop() {
  int power = controller.getAngle();

  power = map(power, 0, 180, 1000, 2000);

  Serial.println(power);
  motor1.writeMicroseconds(power);
  motor2.writeMicroseconds(power);
}