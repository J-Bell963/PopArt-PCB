#include <Adafruit_NeoPixel.h>
#include "frames.h"
Adafruit_NeoPixel strip(24, 0);

int colors[4][3] {
  {255, 255, 255}, // 0, white
  {255, 0, 0}, // 1, red
  {200, 0, 0}, // 2, red
  {150, 0, 0}, // 3, red
  {100, 0, 0}, // 4, red
  {50, 0, 0}, // 5, red
};

unsigned long previousMillis = 0;
int mode = 0;

void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(50);
}

void loop() {
mode = (mode + 1) % 4;
  switch (mode) {

    case 0: off(); break; //off mode
    case 1: on(); break; //constant visulization
    case 2: simpleAnimation(); break; //simple animation
    case 3: mapped(); break; //mapped animation
  }

}

void off(){
  strip.clear();
  strip.show();
}

void on(){
    for (int i = 0; i < strip.numPixels(); i++){
    int red = colors[0][0];
    int green = colors[0][1];
    int blue = colors[0][2];
  strip.setPixelColor(i, red, green, blue);
  }
  strip.show();

}

void simpleAnimation(){
 uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((j) & 255));
    }
    strip.show();
    
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void mapped(){
  unsigned long currentMillis = millis();
  int whichFrame = 0;
 int pixelAddress = pixelMap[i];
    int whichColor = animation[whichFrame][i];
    int red = colors[whichColor][1];
    int blue = colors[whichColor][2];
    int green = colors[whichColor][3];
    if (pixelAddress != -1) {
      strip.setPixelColor(pixelAddress, red, green, blue);
    }
  }
  strip.show();
  if(currentMillis - previousMillis > 200){
  whichFrame = (whichFrame + 1) % 7;
  previousMillis = currentMillis;
  }
}
