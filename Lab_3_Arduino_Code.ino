
#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *left_wheel = AFMS.getMotor(1);
Adafruit_DCMotor *right_wheel = AFMS.getMotor(2);

left_sensor_pin = A0;
right_sensor_pin = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(left_sensor_pin, OUTPUT);
  pinMode(right_sensor_pin, OUTPUT);
  
  left_wheel -> setSpeed(50)
  right_wheel -> setSpeed(50);

  left_wheel -> run(FORWARD);
  right_wheel -> run(FORWARD);

  left_wheel -> run(RELEASE);
  right_wheel -> run(RELEASE);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
