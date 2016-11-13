#include <FastLED.h>

#define NUM_LED 100
#define DATA_PIN 3
#define DELAY 500

CRGB leds[NUM_LED];

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LED);

}

void loop() {
  for(short i=0; i<NUM_LED; i++)
  {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(DELAY);

    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(DELAY);

    leds[i] = CRGB::Green;
    FastLED.show();
    delay(DELAY);

    leds[i] = CRGB::Black;
    FastLED.show();
    
  }

}
