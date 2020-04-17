#include <CapacitiveSensor.h>

#define LED_PIN 0

CapacitiveSensor   cs_3_4 = CapacitiveSensor(3,4);
long sensor_max = 2000;

void setup() {
  cs_3_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
  pinMode(0, OUTPUT);
  for (int i=0;i<3;i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }

//  Serial.begin(9600);
}

void loop() {
  long total =  cs_3_4.capacitiveSensor(30);
  if (total > 0) {
    if (total > sensor_max) {
      total = sensor_max;
    }
    int mapped_val = map(total, 500, sensor_max, 0, 255);
    if (mapped_val > 0) {
      analogWrite(LED_PIN, mapped_val);
    }
    else {
      analogWrite(LED_PIN, 10);
      delay(100);
      analogWrite(LED_PIN, 0);
      delay(100);
    }
  }
}
