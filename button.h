
class BUTTON
{
private:
    boolean status;
    int pin;
    String name;

public:
    BUTTON(int pin, int mode);
    BUTTON(int pin);
    BUTTON();
    boolean read();
    void setName(String);
    String toString();
};

BUTTON::BUTTON(int pin, int mode)
{
    this->pin = pin;
    pinMode(pin, mode);
}

BUTTON::BUTTON(int pin)
{
    this->pin = pin;
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

String BUTTON::toString()
{
    String str = "";
    if (this->name != "")
    {
        str += this->name;
        str += ":";
    }
    str += this->status ? "true " : "false";
    return str;
}