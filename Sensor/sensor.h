#ifndef SENSOR_H_INCLUDED
#define SENSOR_H_INCLUDED
#include <iostream>
#include <wiringPi.h>


class Sensor
{
    protected:

        int m_gpio;

    public:

        Sensor(int numGpio);
        ~Sensor();
        int getGpioValue();
        int getGpioNum();
        void setInput();
        void setOutput();
};

class Led : public Sensor
{
    public :
        Led(int gpio);
        ~Led();
        bool lightOn();
        bool lightOff();
};

class TouchSensor : public Sensor
{	
	public:
		TouchSensor(int gpio);
};


#endif
