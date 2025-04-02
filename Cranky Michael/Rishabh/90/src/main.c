#include <kipr/wombat.h>
void PL90();
int main()
{
    cmpc(3);
    while(gmpc(3)>(2400*-1) + 26)
    {
        motor(0,0);
        motor(3,-50);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
    return 0;
}
void PL90()
{
    cmpc(3);
    while(gmpc(3)<3750-26)
    {
        motor(3,50);
        motor(0,0);
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}