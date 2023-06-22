// Name: lights_to_xyz
// indicates the motion of a Adafruit Circuit Playground with colours corresponding to
// gyroscope value; lights 0,1,3,4 indicate the x value, lights 5,6,8,9 indicate the
// y value, lights 2 & 7 indicate the z value.

#include <Adafruit_CircuitPlayground.h>

float X, Y, Z;

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
}

void loop() {
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

  // if x, y, or z are a value greater than 1, their respective lights turn green
  // if thte directional value is less than 0, their respective lights turn red
  // any values in between are indicated by a blue light.
  if (X > 1) {
    for (int i = 0; i < 5; i++) CircuitPlayground.setPixelColor(i, 0, 255, 0);
  } else if (X < 0) {
    for (int i = 0; i < 5; i++) CircuitPlayground.setPixelColor(i, 255, 0, 0);
  } else {
    for (int i = 0; i < 5; i++) CircuitPlayground.setPixelColor(i, 0, 0, 255);
  }

  if (Y > 1) {
    for (int i = 5; i < 10; i++) CircuitPlayground.setPixelColor(i, 0, 255, 0);
  } else if (Y < 0) {
    for (int i = 5; i < 10; i++) CircuitPlayground.setPixelColor(i, 255, 0, 0);
  } else {
    for (int i = 5; i < 10; i++) CircuitPlayground.setPixelColor(i, 0, 0, 255);
  }

  if (Z > 1) {
    for (int i = 2; i < 10; i = i + 5) CircuitPlayground.setPixelColor(i, 0, 255, 0);
  } else if (Z < 0) {
    for (int i = 2; i < 10; i = i + 5) CircuitPlayground.setPixelColor(i, 255, 0, 0);
  } else {
    for (int i = 2; i < 10; i = i + 5) CircuitPlayground.setPixelColor(i, 0, 0, 255);
  }

  delay(1000);
}