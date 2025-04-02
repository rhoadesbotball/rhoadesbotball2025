#include <kipr/wombat.h>

int main()
{
    wait_for_light(5);
    shut_down_in(119);
    motor(0,50);
    motor(2,0);
    msleep(1500);
    
    motor(0,50);
    motor(2,50);
    msleep(1500);
    return 0;
}
