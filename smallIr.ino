#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include "button.h"

#define LCD_LINE 2
#define LCD_CHAR 16
#define BUTTON_LEN 3
#define BUTTON_BEGIN 2
#define BUTTON_L_PIN 2
#define BUTTON_R_PIN 3
#define BUTTON_ENT_PIN 4
#define LED_PIN 13
#define DHT_PIN 7
LiquidCrystal_I2C lcd(0x27, LCD_CHAR, LCD_LINE);
DHT dht(DHT_PIN, DHT11);

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

BUTTON buttons[BUTTON_LEN];

void setup()
{
    // button
    for (int i = 0; i < BUTTON_LEN; i++)
    {
        buttons[i] = BUTTON(BUTTON_BEGIN + i, INPUT_PULLUP);
        buttons[i].setName(String(i));
        buttons[i].setStrMode(1);
    }

    // led
    pinMode(LED_PIN, OUTPUT);

    // dht
    dht.begin();

    // lcd
    lcd.init();
    lcd.backlight();
}

int masterMode = 0;
int subMode = 0;
bool isRun = false;

void loop()
{
    String printStr = "";
    int lcdPos = 0;
    boolean buttonStatuss[BUTTON_LEN];

    for (int i = 0; i < BUTTON_LEN; i++)
    {
        buttonStatuss[i] = buttons[i].read();
    }

    for (int i = 0; i < BUTTON_LEN; i++)
    {
        printStr += buttons[i].toString() + " ";
    }
    printLcd(lcd, printStr, lcdPos++);

    float pH = dht.readHumidity();
    float tp = dht.readTemperature();

    printStr = "";
    printStr += "T:";
    printStr += String(tp, 1);
    printStr += "C H:";
    printStr += String(pH, 1);
    printStr += "%";
    printLcd(lcd, printStr, lcdPos);

    delay(100);
}
