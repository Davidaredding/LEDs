#include <FastLED.h>

#define NUM_LED 100
#define DATA_PIN 3
#define DELAY 30
#define H 10
#define W 10


int x_min_max[2];

CRGB leds[NUM_LED];

  void setup() {
    FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LED);
  }

//  int  pos[10][10] = {
//    {0,0,0,0,0,0,0,0,0,0},
//    {0,0,0,1,1,1,1,0,0,0},
//    {0,0,1,1,1,1,1,1,0,0},
//    {0,1,1,0,1,0,1,1,1,0},
//    {0,1,1,0,1,0,1,1,1,0},
//    {0,1,1,1,1,1,1,1,1,0},
//    {0,1,0,1,1,1,0,1,1,0},
//    {0,0,1,0,0,0,1,1,0,0},
//    {0,0,0,1,1,1,1,0,0,0},
//    {0,0,0,0,0,0,0,0,0,0}
//    
//  };

  int  pos[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,1,0,0},
    {0,0,0,1,1,1,1,0,0,0},
    {0,0,1,1,1,1,1,1,0,0},
    {0,1,1,0,1,1,0,1,1,0},
    {0,1,1,1,0,0,1,1,1,0},
    {0,0,1,1,0,0,1,1,0,0},
    {0,1,0,1,0,0,1,0,1,0},
    {0,1,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0}
    
  };
  
  void loop() 
  {  
      int val;
      for(int y=0; y<H; y++)
      {
          for(int x=0;x<H; x++)
          {
              if(pos[y][x] == 1)
              {
                 if(x%2==0)
                  {
                    val =  (x*W)+y;
                  }
                  else
                  {
                     val = ((x*W)+(W-1))-y;
                  }
                  leds[val]= CRGB::Gold;
                          
              }
          }
        
      }
    
        FastLED.show();
        delay(100);
      
      
  }


  void X(int x)
  {
    int _max = x*H+(H-1);
    int _min = x*H;
    x_min_max[0] = _max;
    x_min_max[1] = _min;
  }
  
  int Y(int y,int x, int x_max, int x_min)
  {
    if(x%2==0 || x==0){
      return y - x_min;
    }
    else{
      return y + x_max;
    }
    return 0;
  }



