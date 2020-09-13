#include <Servo.h>

int distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_6;

void setup()
{
  pinMode(4, OUTPUT);
  servo_6.attach(6);

}

void loop()
{
  distance = 0.01723 * readUltrasonicDistance(11, 10);
  if (distance < 50) {
    digitalWrite(4, HIGH);
    servo_6.write(90);
  } else {
    servo_6.write(0);
    digitalWrite(4, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}