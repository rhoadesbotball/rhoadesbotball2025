#include <kipr/wombat.h>
void drive(int distance);
void driveb(int distance);
void L90();
void R90();
int adj = 14;
int main()
{
    R90();
    return 0;
}
void drive(int distance)
{
    cmpc(0);
    while(gmpc(0)<distance-26)
    {
        motor(0,80);
        motor(3,80+adj);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
}
void driveb(int distance)
{
    cmpc(0);
    while(gmpc(0)>(distance*-1) + 26)
    {
        motor(0,-80);
        motor(3,-80-adj);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
}
void L90()
{
    cmpc(0);
    while(gmpc(0)<1200 - 26)
    {
        motor(0,50);
        motor(3,-50);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
}
void R90()
{
    cmpc(0);
    while(gmpc(0)>(750*-1) + 26)
    {
        motor(0,-80);
        motor(3,80);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
}