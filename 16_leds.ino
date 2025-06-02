int rowPins[4] = {2, 3, 4, 5};   // Rows
int colPins[4] = {6, 7, 8, 9};   // Columns

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(rowPins[i], OUTPUT);
    pinMode(colPins[i], OUTPUT);
  }
}

void loop() {
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      // Turn off all LEDs
      clearMatrix();

      // Light up one LED at a time
      digitalWrite(rowPins[r], HIGH);
      digitalWrite(colPins[c], LOW);

      delay(100);
    }
  }
}

void clearMatrix() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(rowPins[i], LOW);
    digitalWrite(colPins[i], HIGH);
  }
}
