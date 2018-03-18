#include "sensor.h"


using namespace std;

void interrupt()
{
		cout<< "l'interruption a eu lieu\n";
}

	
PI_THREAD (myThread)
{
	while (1)
	{
		wiringPiISR(3, INT_EDGE_RISING,  interrupt);
		waitForInterrupt(3, -1);
		cout <<"allumé\n";
		wiringPiISR(3, INT_EDGE_FALLING,  interrupt);
		waitForInterrupt(3, -1);
		cout <<"éteind\n";
	}
}

int main()
{
    if (wiringPiSetup() == -1)
    {
        cout << "erreur\n";
        return 0;
    }
	Led led(0,"PWM_OUTPUT");
	TouchSensor touchSensor(3);

	led.lightOn(1000);
	/*int x = piThreadCreate(myThread);
	if (x != 0)
		cout << "problem\n";
	else 
		cout << "thread thrown\n";*/
	
	delay(300);
	
/*	
int i(0);
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
    
}*/

return 0;
}


