#include "sensor.h"

/*###########################--SENSOR--###########################"*/

//init Sensor
Sensor::Sensor(int numGpio) : m_gpio(numGpio), m_mode("")
{}

//destroy Sensor
Sensor::~Sensor()
{}

int Sensor::getGpioNum() const 
{
    return m_gpio;
}

int Sensor::getGpioValue() const
{
    return digitalRead(m_gpio);
}

void Sensor::setInput()
{
	pinMode(m_gpio, INPUT);
	m_mode = "INPUT";
}

void Sensor::setOutput()
{
	pinMode(m_gpio, OUTPUT);
	m_mode = "OUTPUT";
}

//set mode PWM_OUTPUT, must check if it's run as root
void Sensor::setPwm()
{
	if ((std::string)getenv("USER") == "root")
	{
		pinMode(m_gpio, PWM_OUTPUT);
		m_mode = "PWM_OUTPUT";
	}
	else 
		std::cout << "must run as root to use PWD_OUTPUT\n";
}

/*###########################--LED--###########################"*/

//Led constructor output by default 
Led::Led(int gpio) : Sensor(gpio)
{
    this->setOutput();
}

//Led constructor output or PWM_OUTPUT
Led::Led(int gpio,std::string mode) : Sensor(gpio)
{
	if (mode == "OUTPUT")
		this->setOutput();
	else if (mode == "PWM_OUTPUT" && gpio == 1)
		this->setPwm();
	else 
	{
		std::cout<<"failed to define Led " << m_gpio<<std::endl;
	}
}

Led::~Led()
{
	this->lightOff();
}


bool Led::lightOn()
{	
	if (m_mode == "OUTPUT")
		digitalWrite(m_gpio, HIGH);
    return true;
}

bool Led::lightOn(int i)
{	
	if( i<0 || i>1023)
	{
		return false;
	}
	if (m_mode == "PWM_OUTPUT")	
		pwmWrite(m_gpio, i);
    return true;
}

bool Led::lightOff()
{
    //std::cout<<"éteignage led\n";
    if (m_mode == "PWM_OUTPUT")
		pwmWrite(m_gpio, LOW);
	else if (m_mode == "OUTPUT")
		digitalWrite(m_gpio, LOW);
    return true;
}

/*###########################--TOUCHSENSOR--###########################"*/


TouchSensor::TouchSensor(int gpio) : Sensor(gpio)
{
	this->setInput();
}
