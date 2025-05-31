//Bluetooth controlled LED using Arduino
char incomingChar;

void setup() {
  pinMode(13, OUTPUT); // LED pin
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  if (Serial.available()) {
    incomingChar = Serial.read();
    if (incomingChar == '1') {
      digitalWrite(13, HIGH); // Turn LED ON
    } else if (incomingChar == '0') {
      digitalWrite(13, LOW); // Turn LED OFF
    }
  }
}
