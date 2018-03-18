#ifndef SENSOR_H_INCLUDED
#define SENSOR_H_INCLUDED
#include <iostream>
#include <wiringPi.h>
#include <string>

/*############################################################*/

class Sensor
{
    protected:

        int m_gpio;
		std:: string m_mode;
		
    public:

        Sensor(int numGpio);
        ~Sensor();
        int getGpioValue() const;
        int getGpioNum() const;
        void setInput();
        void setOutput();
        void setPwm();
};

/*############################################################*/

class Led : public Sensor
{
    public :
        Led(int gpio);
        Led(int gpio, std::string mode);
        ~Led();
        bool lightOn();
        bool lightOn(int i);
        bool lightOff();
};

/*############################################################*/

class TouchSensor : public Sensor
{	
	public:
		TouchSensor(int gpio);
};

/*############################################################*/

#endif
