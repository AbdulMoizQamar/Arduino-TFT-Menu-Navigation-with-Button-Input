#include <SPI.h>
#include <TFT_eSPI.h>

#define TFT_MISO 37
#define TFT_MOSI 35
#define TFT_SCLK 36
#define TFT_CS   39  // TFT chip select
#define TFT_DC   2  // TFT data/command
#define TFT_RST  4  // TFT reset (-1 if not used)

int buttonPin = 12;          
int menuIndex = 0;           

TFT_eSPI tft = TFT_eSPI();  // Initialize TFT

//Function Declaration
void showMenu();

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT_PULLUP);              
  showMenu();

  tft.begin();
  tft.setRotation(1); // Adjust rotation (1 = landscape)
 // int downloadpercent = 50;
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(3);      // Set text size
  tft.setTextColor(TFT_BLUE,TFT_BLACK);  // White text on blue background
  //tft.setCursor(80, 70);   // Set cursor position (X=0, Y=10)
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {  
    delay(300);                         
    menuIndex = menuIndex + 1;
    if (menuIndex > 2) {
      menuIndex = 0;
    }

    showMenu();
    while (digitalRead(buttonPin) == LOW);
    delay(100);
  }
}

void showMenu() {
  if (menuIndex == 0) {
    tft.fillScreen(TFT_BLACK);
    Serial.println("Show Temperature");
    tft.setCursor(0, 5);
    tft.println("Temperature");
  } 
  else if (menuIndex == 1) {
    tft.fillScreen(TFT_BLACK);
    Serial.println("Show Acceleration");
    tft.setCursor(0, 160);
    tft.println("Acceleration");
  } 
  else if (menuIndex == 2) {
    tft.fillScreen(TFT_BLACK);
    Serial.println("Show Time");
    tft.setCursor(0, 90);
    tft.println("Current Time");
  }
}