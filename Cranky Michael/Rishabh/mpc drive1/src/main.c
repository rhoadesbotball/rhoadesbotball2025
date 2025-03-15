#include <kipr/wombat.h>
void mpcdrive12(int speed, int ticks);//THIS IDEA WAS A RISHAHRAN PRODUCTION WITH ALL IDEAS GOING TO AHRAN
int main()
{
    mpcdrive12(80, 10000);
    return 0;
}
void mpcdrive12(int speed, int ticks)// PERFECTLY STRAIGHT DRIVE WITH MOTOR POSITION COUNTER
{
    cmpc(0);
    cmpc(3);
    while(gmpc(0)<ticks || gmpc(3)<ticks)
    {
        if(gmpc(0)==gmpc(3))
        {
            motor(0,speed);
            motor(3,speed);
        }
        else if(gmpc(0)>gmpc(3))
        {
            motor(0,speed-10);
            motor(3,speed);
        }
        else if(gmpc(0)<gmpc(3))
        {
            motor(0,speed);
            motor(3,speed-10);
        }
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}
       