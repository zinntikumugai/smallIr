
class BUTTON
{
private:
    boolean status;
    int strMode;
    int pin;
    String name;

public:
    BUTTON(int pin, int mode);
    BUTTON(int pin);
    BUTTON();
    boolean read();
    void setName(String);
    void setStrMode(int);
    String toString();
};

BUTTON::BUTTON(int pin, int mode)
{
    this->pin = pin;
    this->strMode = 0;
    pinMode(pin, mode);
}

BUTTON::BUTTON(int pin)
{
    this->pin = pin;
    this->strMode = 0;
    pinMode(pin, INPUT_PULLUP);
}
BUTTON::BUTTON()
{
}

boolean BUTTON::read()
{
    boolean status = !digitalRead(this->pin);
    this->status = status;
    return status;
}

void BUTTON::setName(String name)
{
    this->name = name;
}

void BUTTON::setStrMode(int mode) {
    this->strMode = mode;
}

String BUTTON::toString()
{
    String str = "";
    if (this->name != "")
    {
        str += this->name;
        str += ":";
    }
    if (        this->strMode == 0)
    {
        str += this->status ? "true " : "false";
    }else {
        str += this->status ? "1" : "0";
    }

    return str;
}