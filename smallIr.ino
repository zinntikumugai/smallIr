#include <Wire.h>
#include <DHT.h>
#include "button.h"
#include "lcdDatas.h"

#define LCD_LINE 2
#define LCD_CHAR 16
#define BUTTON_LEN 3
#define BUTTON_BEGIN 2
#define LED_PIN 13
#define DHT_PIN 7
LiquidCrystal_I2C lcd(0x27, LCD_CHAR, LCD_LINE);
lcdDatas lcdD = lcdDatas(0x27, LCD_CHAR, LCD_LINE);
DHT dht(DHT_PIN, DHT11);

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
boolean isRun = false;

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
    lcdD.append(printStr);
    lcdD.append("\n");

    float pH = dht.readHumidity();
    float tp = dht.readTemperature();

    printStr = "";
    printStr += "T:";
    printStr += String(tp, 1);
    printStr += "C H:";
    printStr += String(pH, 1);
    printStr += "%";
    
    lcdD.append(printStr);
    lcdD.show(lcd);

    delay(100);
}
