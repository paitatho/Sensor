#ifndef SENSOR_H_INCLUDED
#define SENSOR_H_INCLUDED
#include <iostream>
#include <wiringPi.h>


class Sensor
{
    private:

        unsigned short m_gpio;

    public:

        Sensor(int numGpio);
        ~Sensor();
        unsigned short getGpioValue();
};

class Led : public Sensor
{
    public :
        Led(int gpio);
        ~Led();
        bool lightOn();
        bool lightoff();
}


#endif
