#include <kipr/wombat.h>

int main()
{
    motor(0,80);
    motor(1,80);
    motor(2,-80);
    motor(3,-80);
    msleep(2000);
    return 0;
}
