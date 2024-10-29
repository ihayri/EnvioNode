#include <TFT_eSPI.h>
#include <DigitalRainAnimation.hpp>
#include "MatrixCodeNFI18.h"

TFT_eSPI tft = TFT_eSPI();
DigitalRainAnimation<TFT_eSPI> matrix_effect = DigitalRainAnimation<TFT_eSPI>();

void setup() {
//  Serial.begin(115200);
//  Serial.println("\n\n TFT_eSPI with Japanese Font");

  pinMode(1, OUTPUT);      // 1st 3904 for LED Display
  pinMode(9, OUTPUT);      // 2nd 3904 for LED Display
  digitalWrite(1, LOW);
  digitalWrite(9, HIGH);
  pinMode(18, OUTPUT);     // AP2822 High Power Switch
  digitalWrite(18, HIGH);

  displayInit();
  delay(500); // Safety
  digitalWrite(1, HIGH);

//  tft.fillScreen(TFT_BLACK);
  tft.loadFont(MatrixCodeNFI18);

  matrix_effect.init(&tft);
}

void loop() {
  matrix_effect.loop();
}

// Display Initialization
void displayInit() {
  tft.init();
  tft.setRotation(2);
  tft.fillScreen(TFT_BLACK);
}