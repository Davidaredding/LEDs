#include <FastLED.h>

#define NUM_LED 50
#define DATA_PIN_1 3
#define DATA_PIN_2 4
#define DELAY

CRGB leds1[NUM_LED];
CRGB leds2[NUM_LED];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811 ,DATA_PIN_1, BRG>(leds1, NUM_LED);
  FastLED.addLeds<WS2811 ,DATA_PIN_2, BRG>(leds2, NUM_LED);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i =0; i<NUM_LED; i++)
  {
    leds1[i] = CRGB::Red;
    leds2[NUM_LED-1-i] = CRGB::LawnGreen;
    FastLED.show();
    delay(DELAY);

    leds1[i] = CRGB::Black;
    leds2[NUM_LED-1-i] = CRGB::Black;
    FastLED.show();
    
    
  }
}
