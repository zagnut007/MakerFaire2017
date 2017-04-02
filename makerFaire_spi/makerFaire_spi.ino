/*********************************************************************
New Orleans Mini Maker Faire 2017 VIP Badge Example Sketch
https://github.com/zagnut007/MakerFaire2017

Author: Kevin Blank

The follow sketch is designed to work with the components supplied
in the 2017 VIP Badge Kit. The LEDs are optional and the badge will
work as designed without them.

Learn more about the NOLA Mini Maker Faire at http://neworleans.makerfaire.com/

Requires:
https://github.com/adafruit/Adafruit-GFX-Library
https://github.com/adafruit/Adafruit_SSD1306

Thank you to Adafruit for providing these libraries!
https://www.adafruit.com/
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// If using software SPI (the default case):
#define OLED_MOSI  9   // SDA pin on OLED
#define OLED_CLK   10  // SCL pin on OLED
#define OLED_DC    8   // D/C pin on OLED
#define OLED_CS    12  // 
#define OLED_RESET 14  // RST pin on OLED
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define LED_1 2
#define LED_2 3
#define LED_3 4

// CHANGE ME - Put your name in the constant below.
#define MYNAME "Kevin"

#define DISPLAY_HEIGHT 64
#define DISPLAY_WIDTH 128

#define LOGO32_GLCD_HEIGHT 32 
#define LOGO32_GLCD_WIDTH  32

// This is the bitmap image of the Maker Faire Robot
static const unsigned char PROGMEM logo32_glcd_bmp[] =
{ B00000000, B00000111, B11100000, B00000000, 
B00000000, B00011111, B11111000, B00000000, 
B00000000, B00111111, B11111100, B00000000, 
B00000000, B00100111, B11100100, B00000000, 
B00000000, B01100111, B11100110, B00000000, 
B00000000, B01100111, B11100110, B00000000, 
B00000000, B01111111, B11111110, B00000000, 
B00000000, B01000000, B00000010, B00000000, 
B00000001, B11111111, B11111111, B10000000, 
B00011101, B11111100, B00111111, B10111000, 
B00111111, B11110000, B00001111, B11111100, 
B01111011, B11101111, B11110111, B11011110, 
B11111011, B11101101, B10110111, B11011111, 
B11111000, B00001101, B10110000, B00011111, 
B11111011, B11101101, B10110111, B11011111, 
B11111011, B11101100, B00110111, B11011111, 
B01111101, B11110000, B00001111, B10111110, 
B00111001, B11111100, B00111111, B10011100, 
B01111101, B11111111, B11111111, B10111110, 
B01111100, B11111111, B11111111, B00111110, 
B01111100, B01111100, B00111110, B00111110, 
B01111100, B01111100, B00111110, B00111110, 
B01111100, B01111100, B00111110, B00111110, 
B01111100, B01111100, B00111110, B00111110, 
B01000100, B11111100, B00111111, B00100010, 
B01111110, B11111100, B00111111, B01111110, 
B00111110, B11111100, B00111111, B01111100, 
B00011100, B11111110, B01111111, B00111000, 
B00000001, B11111110, B01111111, B10000000, 
B00000001, B00000100, B00100000, B10000000, 
B00000011, B11111110, B01111111, B11000000, 
B00000011, B11111110, B01111111, B11000000 };

void setup()   {                
  Serial.begin(9600);

  // Required to set up the display
  display.begin(SSD1306_SWITCHCAPVCC);
  
  // Clear the buffer.
  display.clearDisplay();

  // Set the pin modes for the LEDs
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

  // Initial "boot" screen
  vipSplash(logo32_glcd_bmp, LOGO32_GLCD_HEIGHT, LOGO32_GLCD_WIDTH);
  led_cycle(4);
}



void loop() {
  scrollName();
  display.clearDisplay();
  led_cycle(1);
  
  pong();
  display.clearDisplay();
  led_cycle(1);

  vipSplash(logo32_glcd_bmp, LOGO32_GLCD_HEIGHT, LOGO32_GLCD_WIDTH);
  led_cycle(4);
}


/* Cycles are 1 second a piece */
void led_cycle(int cycleCount){
  int i;
  long randNumber;

  for(i=0;i<(cycleCount*10);i++){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);

    randomSeed(millis());

    randNumber = random(0, 40);
    if(randNumber < 20){
      digitalWrite(LED_1, HIGH);
    }
    else{
      digitalWrite(LED_1, LOW);
    }
    
    randNumber = random(0, 40);
    if(randNumber < 20){
      digitalWrite(LED_2, HIGH);
    }
    else{
      digitalWrite(LED_2, LOW);
    }

    randNumber = random(0, 40);
    if(randNumber < 20){
      digitalWrite(LED_3, HIGH);
    }
    else{
      digitalWrite(LED_3, LOW);
    }

    delay(100);

    
  }

}

void scrollName(){
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println("My name is:");
  display.setTextSize(2);
  display.setCursor(10,10);
  display.println(MYNAME);
  display.display();
 
  display.startscrollright(0x00, 0x1F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);    
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
}

void vipSplash(const uint8_t *bitmap, uint8_t w, uint8_t h){
  int margin = 50;
  
  display.clearDisplay();
  display.drawBitmap(4, 4, bitmap, w, h , 1);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(margin,4);
  display.println("NOLA Mini");
  display.setCursor(margin,12);
  display.println("Maker Faire");
  display.setTextSize(2);
  display.setCursor(margin,24);
  display.println("VIP");
  display.setTextSize(2);
  display.setCursor(margin,40);
  display.println("2017");
  display.display();
  
}

/*
 * Makey Pong
 * There's a good bit going on here because the paddles are built
 * with some basic AI to follow Makey
 */
void pong(){
  int paddleWidth = 4;
  int paddleHeight = 24;
  int paddleYmin = 0;
  int paddleYmax = DISPLAY_HEIGHT - paddleHeight;
  int paddleAxpos = 0;
  int paddleBxpos = DISPLAY_WIDTH - paddleWidth;

  float currentPaddleAy = 12;
  float currentPaddleBy = 32;

  float paddleStep = 1;

  int makeyXmin = paddleWidth + 1;
  int makeyXmax = DISPLAY_WIDTH - (paddleWidth + 1 + LOGO32_GLCD_WIDTH);
  int makeyYmin = 0;
  int makeyYmax = DISPLAY_HEIGHT - LOGO32_GLCD_HEIGHT;
  float makeyXcenter = 47;
  float makeyYcenter = 17;

  float makeyCurrentX = makeyXcenter;
  float makeyCurrentY = makeyYcenter;

  float xStep = 1;
  float yStep = 0.5;
  
  display.fillRect(paddleAxpos, currentPaddleAy, paddleWidth, paddleHeight, 1);
  display.fillRect(paddleBxpos, currentPaddleBy, paddleWidth, paddleHeight, 1);
  display.drawBitmap(makeyCurrentX, makeyCurrentY, logo32_glcd_bmp, 32, 32 , 1);
  display.display();

  int frameLength = 25;
  int i = 0;
  while(i < 7000){
    display.clearDisplay();
    
    // first right
    makeyCurrentX = makeyCurrentX + xStep;
    makeyCurrentY = makeyCurrentY + yStep;

    if(makeyCurrentX >= makeyXmax){
      xStep = -1;
    }
    if(makeyCurrentX <= makeyXmin){
      xStep = 1;
    }
    if(makeyCurrentY >= makeyYmax){
      yStep = -0.5;
    }
    if(makeyCurrentY <= makeyYmin){
      yStep = 0.5;
    }

    // Makey is headed right Only start moving if Makey is on the right side
    if(xStep > 0 && makeyCurrentX > makeyXcenter){
      if((currentPaddleBy/2) > (makeyCurrentY/2) && currentPaddleBy > paddleYmin){
        currentPaddleBy = currentPaddleBy - paddleStep;
      }
      if((currentPaddleBy/2) < (makeyCurrentY/2) && currentPaddleBy < paddleYmax ){
        currentPaddleBy = currentPaddleBy + paddleStep;
      }
    }
    
    // Makey is headed left
    if(xStep < 0 && makeyCurrentX < makeyXcenter){
      if((currentPaddleAy/2) > (makeyCurrentY/2) && currentPaddleAy > paddleYmin){
        currentPaddleAy = currentPaddleAy - paddleStep;
      }
      if((currentPaddleAy/2) < (makeyCurrentY/2) && currentPaddleAy < paddleYmax ){
        currentPaddleAy = currentPaddleAy + paddleStep;
      }
    }
   
    display.fillRect(paddleAxpos, int(currentPaddleAy), paddleWidth, paddleHeight, 1);
    display.fillRect(paddleBxpos, int(currentPaddleBy), paddleWidth, paddleHeight, 1);
    display.drawBitmap(int(makeyCurrentX), int(makeyCurrentY), logo32_glcd_bmp, 32, 32 , 1);
    display.display();
    
    delay(frameLength - 10);
    i = i+frameLength;
  }
  
  delay(500);
}


void testscrolltext(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println("scroll");
  display.display();
 
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);    
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
}
