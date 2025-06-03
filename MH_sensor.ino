const int sensorPin = 2;     // Digital pin connected to sensor's OUT
const int ledPin = 13;       // Onboard LED

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(sensorPin);
  if (sensorValue == LOW) {
    digitalWrite(ledPin, HIGH); // Object detected
    Serial.println("Obstacle detected!");
  } else {
    digitalWrite(ledPin, LOW);  // No object
    Serial.println("No obstacle.");
  }
  delay(500);
}
