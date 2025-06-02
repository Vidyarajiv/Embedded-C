#include <MCUFRIEND_kbv.h>
#include <Adafruit_GFX.h>

#define BLACK   0x0000
#define RED     0xF800
#define WHITE   0xFFFF

#define GAS_SENSOR_PIN A1
#define THRESHOLD 350   // You can adjust this based on your room conditions

MCUFRIEND_kbv tft;

void setup() {
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.setCursor(20, 20);
  tft.print("MQ-6 Gas Detector");
}

void loop() {
  int gasValue = analogRead(GAS_SENSOR_PIN);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  tft.fillRect(20, 60, 200, 40, BLACK);  // Clear previous value
  tft.setCursor(20, 60);
  tft.print("Gas Level: ");
  tft.print(gasValue);

  if (gasValue > THRESHOLD) {
    tft.fillRect(20, 120, 280, 40, RED);
    tft.setTextColor(WHITE, RED);
    tft.setCursor(20, 120);
    tft.print("WARNING: Gas Leak!");
  } else {
    tft.fillRect(20, 120, 280, 40, BLACK);  // Clear warning
  }

  delay(1000);
}
