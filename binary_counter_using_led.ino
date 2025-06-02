// Assign 16 pins to LEDs
int ledPins[16] = {
  2, 3, 4, 5, 6, 7, 8, 9,
  10, 11, 12, 13, A0, A1, A2, A3
};

unsigned int counter = 0;

void setup() {
  for (int i = 0; i < 16; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Display binary value of counter
  for (int i = 0; i < 16; i++) {
    digitalWrite(ledPins[i], (counter >> i) & 1);
  }

  counter++;  // Increment binary counter
  delay(500); // Wait half a second
}
