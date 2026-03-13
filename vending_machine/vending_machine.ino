#include <Servo.h>

// Servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Button pins
const int button1Pin = 2;  
const int button2Pin = 3;  
const int button3Pin = 4;  
const int button4Pin = 5;  

// Last state variables
bool lastState1;
bool lastState2;
bool lastState3;
bool lastState4;

// Busy flags for 3-second run
bool busy1 = false;
bool busy2 = false;
bool busy3 = false;
bool busy4 = false;

void setup() {
  // Attach servos
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);

  // Use internal pull-up resistors
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);

  // Read initial button states
  lastState1 = digitalRead(button1Pin);
  lastState2 = digitalRead(button2Pin);
  lastState3 = digitalRead(button3Pin);
  lastState4 = digitalRead(button4Pin);

  // Stop all servos at startup
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
}

void loop() {
  int current1 = digitalRead(button1Pin);
  int current2 = digitalRead(button2Pin);
  int current3 = digitalRead(button3Pin);
  int current4 = digitalRead(button4Pin);

  // -------------------------
  // CONTROL SERVO 1 (pin 8)
  // -------------------------
  if (!busy1 && current1 == LOW && lastState1 == HIGH) {
    busy1 = true;
    servo1.write(0);
    delay(3000);
    servo1.write(90);
    busy1 = false;
  }

  // -------------------------
  // CONTROL SERVO 2 (pin 9)
  // -------------------------
  if (!busy2 && current2 == LOW && lastState2 == HIGH) {
    busy2 = true;
    servo2.write(0);
    delay(3000);
    servo2.write(90);
    busy2 = false;
  }

  // -------------------------
  // CONTROL SERVO 3 (pin 10)
  // -------------------------
  if (!busy3 && current3 == LOW && lastState3 == HIGH) {
    busy3 = true;
    servo3.write(0);
    delay(3000);
    servo3.write(90);
    busy3 = false;
  }

  // -------------------------
  // CONTROL SERVO 4 (pin 11)
  // -------------------------
  if (!busy4 && current4 == LOW && lastState4 == HIGH) {
    busy4 = true;
    servo4.write(0);
    delay(3000);
    servo4.write(90);
    busy4 = false;
  }

  // Update last states
  lastState1 = current1;
  lastState2 = current2;
  lastState3 = current3;
  lastState4 = current4;
}
