#include <kipr/wombat.h>

void mec(int fr,int fl, int bl, int br, int duration)
{
    motor(0,fr);
    motor(3,fl);
    motor(1,bl);
    motor(2,br);
    msleep(duration);
}
void fwd(int speed,int duration)
{
    motor(0,speed);
    motor(3,speed);
    motor(1,speed);
    motor(2,speed);
    msleep(duration);
}
void strafe(int speed, int duration)
{
    motor(0,speed);
    motor(3,-speed);
    motor(1,-speed);
    motor(2,speed);
    msleep(duration);
}
 







