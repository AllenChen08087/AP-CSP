#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN 7

MFRC522 mfrc522(SS_PIN, RST_PIN);
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH); // HIGH = LED OFF

  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Tap your RFID card...");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Toggle LED
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState ? LOW : HIGH);

  Serial.println(ledState ? "LED ON" : "LED OFF");

  mfrc522.PICC_HaltA();
  delay(500);
}
