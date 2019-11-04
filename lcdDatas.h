#include <LiquidCrystal_I2C.h>

class lcdDatas
{
private:
    int with;
    int heght;
    String strs;
    LiquidCrystal_I2C lcd;

public:
    lcdDatas(int address,int lcdSize, int lcdCol);
    ~lcdDatas();
    void append(String str);
    void show();
    void printLcd(LiquidCrystal_I2C lcd, String str, int pos);
    void show(int);
};

lcdDatas::lcdDatas(int address, int lcdWith, int lcdHeght)
{
    this->lcd = LiquidCrystal_I2C(address,lcdWith,lcdHeght);
    this->lcd.init();
    this->lcd.backlight();
    this->heght = lcdHeght;
    this->with = lcdWith;
}

lcdDatas::~lcdDatas()
{
}

void lcdDatas::append(String str)
{
    this->strs += str;
}

void lcdDatas::show()
{
    this->printLcd(this->lcd, this->strs, 0);
}

void lcdDatas::printLcd(LiquidCrystal_I2C lcd, String str, int pos)
{
    lcd.setCursor(0, pos);
    lcd.print(str.substring(0, this->with));
}
void lcdDatas::show(int pos)
{
    this->printLcd(this->lcd, this->strs, pos);
}
