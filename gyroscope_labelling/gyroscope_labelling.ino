#include <Adafruit_CircuitPlayground.h>

float X, Y, Z;

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
}

void loop() {
  // Mapping X, Y, and Z coordinates
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

  // Printing the current X, Y, and Z coordinates
  Serial.print("X: ");Serial.println(X);
  Serial.print("Y: ");Serial.println(Y);
  Serial.print("Z: ");Serial.println(Z);
  Serial.println();

  delay(1000);
}