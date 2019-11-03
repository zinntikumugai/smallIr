#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "button.h"

#define LCD_LINE 2
#define LCD_CHAR 16
#define BUTTON_L_PIN 2
#define BUTTON_R_PIN 3
#define BUTTON_ENT_PIN 4
#define LED_PIN 13
LiquidCrystal_I2C lcd(0x27, LCD_CHAR, LCD_LINE);

void printLcd(LiquidCrystal_I2C lcd, String str, int pos)
{
    if (pos > LCD_LINE)
    {
        pos = 0;
    }
    if (pos == 0 && str.length() > LCD_CHAR)
    {
        printLcd(lcd, str.substring(0, LCD_CHAR), 0);
        printLcd(lcd, str.substring(LCD_CHAR, LCD_CHAR + LCD_CHAR), 1);
        return;
    }

    lcd.setCursor(0, pos);
    lcd.print(str);
}

BUTTON buttonR;
BUTTON buttonL;
BUTTON buttonE;

void setup()
{
    // button
    buttonR = BUTTON(BUTTON_R_PIN, INPUT_PULLUP);
    buttonL = BUTTON(BUTTON_L_PIN, INPUT_PULLUP);
    buttonE = BUTTON(BUTTON_ENT_PIN, INPUT_PULLUP);
    buttonR.setName("1");
    buttonR.setStrMode(1);
    buttonL.setName("0");
    buttonL.setStrMode(1);
    buttonE.setName("2");
    buttonE.setStrMode(1);

    // led
    pinMode(LED_PIN, OUTPUT);

    // lcd
    lcd.init();
    lcd.backlight();
}

String printStr = "";

void loop()
{
    printStr = "";
    buttonR.read();
    buttonL.read();
    buttonE.read();

    printStr += buttonL.toString() + " ";
    printStr += buttonR.toString() + " ";
    printStr += buttonE.toString();
    printLcd(lcd, printStr, 0);

    delay(100);
}
