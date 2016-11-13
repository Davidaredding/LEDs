#include <FastLED.h>

#define NUM_LED 100
#define DATA_PIN 3
#define DELAY 30
#define H 10
#define W 10

CRGB leds[NUM_LED];

  void setup() {
    FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LED);
  }
  
  void loop() 
  {
    for(short i=0; i<NUM_LED; i++)
    {
      leds[i] = CRGB::White;
      FastLED.show();
      delay(DELAY);
    }
    
    for(short i=0; i<NUM_LED; i++)
    {
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(DELAY);  
    }
  }

int x_min_max[2];

  void X(int x)
  {
    int _max = x*H+(H-1);
    int _min = x*H;
    x_min_max[0] = _max;
    x_min_max[1] = _min;
  }
  
  int Y(int y,int x, int x_max, int x_min)
  {
    if(x%2 || x==0){
      return y + x_max;
    }
    else{
      return y - x_min;
    }
    return 0;
  }



