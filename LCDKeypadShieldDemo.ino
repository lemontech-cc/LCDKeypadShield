/*
    Lemontech Keypad Shield    
    Demo sketch

    v 1.0 - 18/06/2014
*/


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define BUTTON_UP      0
#define BUTTON_DOWN    1
#define BUTTON_LEFT    2
#define BUTTON_RIGHT   3
#define BUTTON_SELECT  4 
#define BUTTON_NONE    5 

LiquidCrystal_I2C lcd(0x20,16,2);  
int previousButton;

void setup()
{
  
  // Init the display
  lcd.init();
 
  // Flash the display
  lcd.print("Lemontech");
  lcd.backlight();
  delay(500);
  lcd.noBacklight();
  delay(500);
  lcd.backlight();
  previousButton = -1;
}

void loop()
{
  // Get the button actually pressed
  int actualButton = getButton(analogRead(0));
  
  // If it is different from the one displayed on the LCD, change the text
  if(previousButton != actualButton) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pressed-> ");
    if(actualButton == BUTTON_RIGHT) lcd.print("RIGHT");
    else if(actualButton == BUTTON_UP) lcd.print("UP");
    else if(actualButton == BUTTON_DOWN) lcd.print("DOWN");  
    else if(actualButton == BUTTON_LEFT) lcd.print("LEFT");
    else if(actualButton == BUTTON_SELECT) lcd.print("SELECT");  
    else if(actualButton == BUTTON_NONE) lcd.print("none");  
    previousButton = actualButton;
  }
}

// Get the pressed button based on the analog value on the AN0 pin
int getButton(int analogValue) 
{
  if(analogValue < 80) return BUTTON_RIGHT;
  if(analogValue < 250) return BUTTON_UP;
  if(analogValue < 400) return BUTTON_DOWN;
  if(analogValue < 600) return BUTTON_LEFT;
  if(analogValue < 860) return BUTTON_SELECT;
  else return BUTTON_NONE;
}
