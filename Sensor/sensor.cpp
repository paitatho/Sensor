#include "sensor.h"

Sensor::Sensor(int numGpio) : m_gpio(numGpio)
{}

Sensor::~Sensor()
{}

unsigned short Sensor::getGpioValue()
{
    return m_gpio;
}

Led::Led(int gpio) : Sensor(gpio)
{}

Led::~Led()
{}
bool Led::lightOn()
{
    digitalWrite(m_gpio, HIGH);
}
bool Led::lightoff()
{
    digitalWrite(m_gpio, LOW);
}
