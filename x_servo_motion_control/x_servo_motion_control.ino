// Name: x_servo_motion_control
// Lights indicate the x value and the attached motor moves in a determined direction
// based on the x value.

#include <Adafruit_CircuitPlayground.h>
#include <Servo.h>

float X;
Servo servo_x;
int pin_x = 9; // A2 pin for servo x
int cur_servo_val_x = 0;

void setup() {
  CircuitPlayground.begin();
  servo_x.attach(pin_x);
  servo_x.write(0);
  Serial.begin(9600);
}

void loop() {
  X = CircuitPlayground.motionX();

  if (X > 1) {
    for (int i = 0; i < 10; i++) CircuitPlayground.setPixelColor(i, 0, 255, 0);
    for (int i = 0; i < 30; i++) {
      servo_x.write(cur_servo_val_x + i);
      delay(15);
    } cur_servo_val_x += 20;
  } else if (X < 0) {
    for (int i = 0; i < 10; i++) CircuitPlayground.setPixelColor(i, 255, 0, 0);
    for (int i = 0; i < 30; i++) {
      servo_x.write(cur_servo_val_x - i);
      delay(15);
    } cur_servo_val_x -= 20;
  } else {
    for (int i = 0; i < 10; i++) CircuitPlayground.setPixelColor(i, 0, 0, 255);
  }

  delay(1000);
}