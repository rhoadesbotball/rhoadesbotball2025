#include <kipr/wombat.h>

int main()
{
  
    motor(0, 100);
    motor(2, 100);
    msleep(1750);
    motor(2, 0);
    msleep(1600);
    motor(2, 100);
    msleep(6000);
    motor(0, 0);
    msleep(1200);
    motor(2, -50);
    msleep(750);
    motor(0, 100);
    motor(2, 100);
    msleep(2000);

}
