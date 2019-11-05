
#include <LiquidCrystal_I2C.h>
class lcdDatas
{
private:
    int with;
    int heght;
    String strs;

public:
    lcdDatas(int, int, int);
    ~lcdDatas();
    void append(String);
    void show(LiquidCrystal_I2C);
    void clear();
    void printLcd(LiquidCrystal_I2C, String, int);
};

lcdDatas::lcdDatas(int address, int lcdWith, int lcdHeght)
{
    this->heght = lcdHeght;
    this->with = lcdWith;
}

lcdDatas::~lcdDatas()
{
}

void lcdDatas::append(String str)
{
    if (str.equals("\n"))
    {
        int max = this->strs.length();
        for (; max > this->with; max -= this->with)
            ;
        max = this->with - this->strs.length();
        for (int i = 0; i < max; i++)
        {
            this->strs += " ";
        }
    }
    else
    {
        this->strs += str;
    }
}

void lcdDatas::clear() {
    this->strs = "";
}

void lcdDatas::show(LiquidCrystal_I2C lcd)
{
    if (this->strs.length() > this->with)
    {
        int i = 0;
        for (int i = 0; i < this->heght; i++)
        {
            String str = this->strs.substring(i * this->with, (i + 1) * this->with);
            this->printLcd(lcd, str, i);
        }
    }
    else
    {
        this->printLcd(lcd, this->strs, 0);
    }
    this->strs = "";
}

void lcdDatas::printLcd(LiquidCrystal_I2C lcd, String str, int pos)
{
    lcd.setCursor(0, pos);
    lcd.print(str.substring(0, this->with));
}
