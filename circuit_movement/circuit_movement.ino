// Name: curcuit_movement
// Using it's gyroscope functions, the curcuit playground will control
// two motors. The Y-tilt will control forward and backward movement. The
// X-tilt will control turning.

#include <Adafruit_CircuitPlayground.h>

float X, Y;

int motor1pin1 = 3; // A4
int motor1pin2 = 10; // A3

int motor2pin1 = 2; // A5
int motor2pin2 = 9; // A2

void setup() {
  CircuitPlayground.begin();
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Mapping X and Y coordinates
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();

  if (Y > 2) { // Move forward  
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
  } else if (Y < -2) { // move backwards
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
  } else if (X > 2) { // Turn left, Right wheel only
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
  } else if (X < -2) { // Turn right, Left wheel only
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
  } else { // No movement option
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
  }

  // Coordinate check for testing
  Serial.print("X: ");Serial.println(X);
  Serial.print("Y: ");Serial.println(Y);
  Serial.println();
  delay(1000);
}