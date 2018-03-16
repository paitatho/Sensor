
#include "sensor.h"


using namespace std;

int main()
{
    if (wiringPiSetup() == -1)
    {
        cout << "erreur\n";
        return 0;
    }
	Led led(0);
	TouchSensor touchSensor(2);
	int i(0);
	led.lightOn();
/*
while (1)
{
    if (touchSensor.getGpioValue() == 1 && i ==0)
    {
		led.lightOn();
		i=1;
	}
	else if (touchSensor.getGpioValue() == 0 && i==1)
	{
		led.lightOff();
		i=0;
	}
    
}
*/
return 0;
}
