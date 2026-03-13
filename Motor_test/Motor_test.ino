#include <Servo.h>

Servo s; // Create a servo object

const int buttonPin = 2;  // Pin connected to the OUT of the button
int buttonState = 0;      
int lastButtonState = 0;  

const int restPos = 60;    // Original position
const int tapPos = 270;    // "Quick move" position

void setup() {
  s.attach(9);                 // Attach the servo to pin 9
  pinMode(buttonPin, INPUT);   // Set the button pin as input
  s.write(restPos);            // Make sure servo starts at rest
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Detect button press (falling edge)
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(50);  // Simple debounce

    // Move quickly to tap position
    s.write(tapPos);
    delay(150);   // Short pause (adjust speed of "tap")

    // Return to rest position
    s.write(restPos);
  }

  lastButtonState = buttonState;
}
