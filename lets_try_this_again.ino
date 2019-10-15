#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *left_wheel = AFMS.getMotor(1);
Adafruit_DCMotor *right_wheel = AFMS.getMotor(2);
int left_sensor = A1;
int right_sensor = A0;
int fast_wheel = 50;
int slow_wheel = 20;
int slower_wheel = 13;

int left_motor_speed = 0;
int right_motor_speed = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  AFMS.begin();
  
  left_wheel -> setSpeed(20);
  right_wheel -> setSpeed(20);

  left_wheel -> run(BACKWARD);
  right_wheel -> run(BACKWARD);

  left_wheel -> run(RELEASE);
  right_wheel -> run(RELEASE);
  
}

void loop() {
  int left_sensor_value = analogRead(left_sensor);
  int right_sensor_value = analogRead(right_sensor);
  
  right_wheel -> run(BACKWARD);
  
  if (analogRead(left_sensor) > 950)
  {
    right_motor_speed = fast_wheel;
    left_motor_speed = slower_wheel;
    right_wheel -> setSpeed(fast_wheel);
    left_wheel -> setSpeed(slower_wheel);    
  }
  else
  {
    right_motor_speed = slow_wheel;
    right_wheel -> setSpeed(slow_wheel);
  }
  left_wheel -> run(BACKWARD);
  if (analogRead(right_sensor) > 970)
  {
    left_motor_speed = fast_wheel;
    right_motor_speed = slower_wheel;
    left_wheel -> setSpeed(fast_wheel);
    right_wheel -> setSpeed(slower_wheel);
  }
  else
  {
    left_motor_speed = slow_wheel;
    left_wheel -> setSpeed(slow_wheel);
  }
  Serial.print('\n');
  Serial.print(millis());
  Serial.print(',');
  Serial.print(left_sensor_value);
  Serial.print(',');
  Serial.print(right_sensor_value);
  Serial.print(',');
  Serial.print(left_motor_speed);
  Serial.print(',');
  Serial.print(right_motor_speed);
}
