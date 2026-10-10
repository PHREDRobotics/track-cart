#include <Servo.h>
#include <ServoInput.h>

enum State {
  DRIVE,
  READY,
  POWERED,
  FAULT,
}

constexpr int MOTOR_1_PIN = 13;
constexpr int MOTOR_2_PIN = 12;
Servo motor1;
Servo motor2;
ServoInputPin<3> controller;
State currentState = POWERED;

void setup() {
	controller.attach();
  motor1.attach(MOTOR_1_PIN);
  motor2.attach(MOTOR_2_PIN);

  Serial.begin(9600);
}

void loop() {
  switch currentState {
    case DRIVE:

  }
  int power = controller.getAngle();

  power = map(power, 0, 180, 1000, 2000);

  Serial.println(power);
  motor1.writeMicroseconds(power);
  motor2.writeMicroseconds(power);
}

void drive(double drive, double turn) {
  
}

class PID {
  double kp, ki, kd;
  double integral, previous_error = 0;
  double dt = 0.02;

  public:
    
    PID(double p, double i, double d) {
      kp = kp;
      ki = ki;
      kd = kd;
    }

    double calculate(double setpoint, double reference) {
      double error = setpoint - reference;

      double p = error;
      double i = integral + error * dt;
      double d = (error - previous_error) / dt;

      previous_error = error;
      integral = i;

      output = p * kp + i * ki + d * kd;

      return output;
    }
};