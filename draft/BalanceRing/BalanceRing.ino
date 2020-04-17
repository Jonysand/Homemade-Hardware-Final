#include <math.h>

// Gyroscope
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_L3GD20_U.h>
/* Assign a unique ID to this sensor at the same time */
Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);
/* the regigster where data is writen */
sensors_event_t event;
/* direction of tilting */
double theta;
/* index of led according to the tilting direction */
int ledIndex;
/* radian of tilting, squared */
double tilting;

// Neopixel
#include <Adafruit_NeoPixel.h>
#define LED_PIN    6
#define LED_COUNT 12
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int n = 0;
int red = 128;
int green = 128;
int blue = 128;
uint32_t ledColor = strip.Color(red, green, blue);
/* LED indexes from -PI to PI */
int ledList[12] = {8,7,6,5,4,3,2,1,0,11,10,9};


void setup() {
  // Gyroscope
  Serial.begin(9600);
  gyro.enableAutoRange(true);
  if(!gyro.begin())
  {
    Serial.println("Ooops, no L3GD20 detected ... Check your wiring!");
    while(1);
  }

  // Neopixel
  strip.begin();
}

void loop() {
  gyro.getEvent(&event);
  theta = atan2(event.gyro.y, event.gyro.x) + PI;
  ledIndex = theta/(PI/6);
  tilting = pow(event.gyro.y, 2)+pow(event.gyro.x, 2);
  if(tilting > 1){
    strip.setPixelColor(ledList[ledIndex], ledColor);
    strip.show();
  }else{
    strip.fill();
    strip.show();
  }
}
