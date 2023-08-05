// finnicky, does not always function as expected

#include <Adafruit_CircuitPlayground.h>
#include <Servo.h>

float X, Y;
Servo servo_x;
Servo servo_y;
int pin_x = 9; // A2 pin for servo x
int pin_y = 6; // A1 pin for servo y
int cur_servo_val_x = 0;
int cur_servo_val_y = 0;

void setup() {
  CircuitPlayground.begin();
  servo_x.attach(pin_x);
  servo_y.attach(pin_y);
  servo_x.write(0);
  servo_y.write(0);
  Serial.begin(9600);
}

void loop() {
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();

  if (X > 1) {
    for (int i = 0; i < 5; i++) CircuitPlayground.setPixelColor(i, 0, 255, 0);
    for (int i = 0; i < 20; i++) {
      servo_x.write(cur_servo_val_x + i);
      delay(15);
    } cur_servo_val_x += 20;
  } else if (X < 0) {
    for (int i = 0; i < 5; i++) CircuitPlayground.setPixelColor(i, 255, 0, 0);
    for (int i = 0; i < 20; i++) {
      servo_x.write(cur_servo_val_x - i);
      delay(15);
    } cur_servo_val_x -= 20;
  } else {
    for (int i = 0; i < 5; i++) CircuitPlayground.setPixelColor(i, 0, 0, 255);
  }

  if (Y > 1) {
    for (int i = 5; i < 10; i++) CircuitPlayground.setPixelColor(i, 0, 255, 0);
    for (int i = 0; i < 20; i++) {
      servo_y.write(cur_servo_val_y + i);
      delay(15);
    } cur_servo_val_y += 20;
  } else if (Y < 0) {
    for (int i = 5; i < 10; i++) CircuitPlayground.setPixelColor(i, 255, 0, 0);
    for (int i = 0; i < 20; i++) {
      servo_y.write(cur_servo_val_y - i);
      delay(15);
    } cur_servo_val_y -= 20;
  } else {
    for (int i = 5; i < 10; i++) CircuitPlayground.setPixelColor(i, 0, 0, 255);
  }

  delay(1000);
}