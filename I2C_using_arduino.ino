#include <Wire.h>

char receivedChar;

void setup() {
  Wire.begin(8); // Set I2C address to 8
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
}

void loop() {
  delay(100);
}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    receivedChar = Wire.read();
    Serial.print("Received from master: ");
    Serial.println(receivedChar);
  }
}

void requestEvent() {
  Wire.write(receivedChar + 1); // Send response (incremented char)
}
