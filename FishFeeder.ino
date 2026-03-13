#include <Servo.h>

Servo myServo;
int relayPin = 7;
unsigned long previousMillis = 0;
const long interval = 43200000;
bool servoAtMax = false;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  myServo.attach(5);
  myServo.write(0);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (servoAtMax) {
      myServo.write(0);
    } else {
      myServo.write(156);
    }

    servoAtMax = !servoAtMax;
  }

  digitalWrite(relayPin, HIGH);
}
