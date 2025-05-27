void setup() {
  // Initialize UART communication at 9600 baud
  Serial.begin(9600);
  Serial.println("UART Communication Started");
}

void loop() {
  // Send a message every second
  Serial.println("Hello from Arduino");
  delay(1000);

  // Read data if available
  if (Serial.available() > 0) {
    char received = Serial.read(); // Read one byte
    Serial.print("Received: ");
    Serial.println(received);
  }
}
