#include <Adafruit_NeoPixel.h>

#define LED_PIN    6
#define LED_COUNT 12

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int n = 0;
int red = 128;
int green = 128;
int blue = 128;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.setPixelColor(n, red, green, blue);
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:

}
