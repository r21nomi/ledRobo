/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
int theta;
static int DOT_COUNT = 8;

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
  theta = 90;
}

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 };

void loop() {
//  matrix.clear();
//  matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
//  matrix.writeDisplay();
//  delay(500);

//  matrix.clear();
//  matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
//  matrix.writeDisplay();
//  delay(500);
//
//  matrix.clear();
//  matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
//  matrix.writeDisplay();
//  delay(500);
//
//  matrix.clear();      // clear display
//  matrix.drawPixel(0, 0, LED_ON);  
//  matrix.writeDisplay();  // write the changes we just made to the display
//  delay(500);
//
//  matrix.clear();
//  matrix.drawLine(0,0, 7,7, LED_ON);
//  matrix.writeDisplay();  // write the changes we just made to the display
//  delay(500);
//
  matrix.clear();
  // sinの範囲が-1 ~ 1だとmapかけた時にあまり値が変わらないので10をかけておく
  float size = 10 * sin(radians(theta));
  int val = map(size, -10, 10, 2, DOT_COUNT + 1);
  int start = (DOT_COUNT - val) / 2;
  matrix.fillRect(start, start, val, val, LED_ON);
  matrix.writeDisplay();
  delay(30);
  theta += 10;
//
//  matrix.clear();
//  matrix.drawCircle(3, 3, 3, LED_ON);
//  matrix.writeDisplay();  // write the changes we just made to the display
//  delay(500);

//  matrix.setTextSize(1);
//  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
//  matrix.setTextColor(LED_ON);
//  // lenの値は右に流れたテキストが最後まで表示されるだけのドットの数を設定
//  for (int8_t x=0, len = -104; x >= len ; x--) {
//    matrix.clear();
//    matrix.setCursor(x,0);
//    matrix.print("Ryota Niinomi");
//    matrix.writeDisplay();
//    delay(100);
//  }
  
//  matrix.setRotation(3);
//  for (int8_t x=7; x>=-36; x--) {
//    matrix.clear();
//    matrix.setCursor(x,0);
//    matrix.print("World");
//    matrix.writeDisplay();
//    delay(100);
//  }
//  matrix.setRotation(0);
}
