
class lcdDatas
{
private:
    int with;
    int heght;
    String strs;
    LiquidCrystal_I2C lcd;

public:
    lcdDatas(int, int, int);
    ~lcdDatas();
    void append(String);
    void show();
    void printLcd(String, int);
    void show(int);
};

lcdDatas::lcdDatas(int address, int lcdWith, int lcdHeght)
{
    this->lcd = LiquidCrystal_I2C(address, lcdWith, lcdHeght);
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
    this->printLcd(this->strs, 0);
}

void lcdDatas::printLcd(String str, int pos)
{
    this->lcd.setCursor(0, pos);
    this->lcd.print(str.substring(0, this->with));
}
void lcdDatas::show(int pos)
{
    this->printLcd(this->strs, pos);
}
