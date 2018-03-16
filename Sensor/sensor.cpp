#include "sensor.h"

Sensor::Sensor(int numGpio) : m_gpio(numGpio)
{}

Sensor::~Sensor()
{}

int Sensor::getGpioNum()
{
    return m_gpio;
}

int Sensor::getGpioValue()
{
    return digitalRead(m_gpio);
}

void Sensor::setInput()
{
	pinMode(m_gpio, INPUT);
}
void Sensor::setOutput()
{
	pinMode(m_gpio, OUTPUT);
}

Led::Led(int gpio) : Sensor(gpio)
{
    this->setOutput();
}

Led::~Led()
{
	this->lightOff();
}
bool Led::lightOn()
{
    std::cout<<"allumage led\n";
    digitalWrite(m_gpio, HIGH);
    return true;
}
bool Led::lightOff()
{
    std::cout<<"éteignage led\n";
    digitalWrite(m_gpio, LOW);
    return true;
}

TouchSensor::TouchSensor(int gpio) : Sensor(gpio)
{
	this->setInput();
}
