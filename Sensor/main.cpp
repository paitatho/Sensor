
#include "sensor.h""


using namespace std;

int main()
{
    if (digitalPiSetup == -1)
    {
        cout << "erreur\n";
        return 0;
    }

    Led led(0);
    led.lightOn();
    delay (3000);
    led.lightOff();

    return 0;
}
