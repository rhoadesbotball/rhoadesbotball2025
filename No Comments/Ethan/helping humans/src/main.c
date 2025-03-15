#include <kipr/wombat.h>
void mec(speed1,speed2,speed3,speed4,duration);
int main()
{
    mec(100,-100,-100,100,1000);
    return 0;
}
void mec(speed1,speed2,speed3,speed4,duration)
{
    motor(0,speed1);
    motor(3,speed2);
    motor(1,speed3);
    motor(2,speed4);
    msleep(duration);
    
}