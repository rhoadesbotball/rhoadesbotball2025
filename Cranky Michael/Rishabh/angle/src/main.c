#include <kipr/wombat.h>
void spin(int angle, int direction);
void pivot(int angle, int motor1);
int l = 1;
int r = 0;
int main()
{
    return 0;
}
void spin(int angle, int direction)
{
    double a90 = 1080;
    double mult = angle/90;
    double cm = a90*mult;
    cmpc(0);
    printf("Hi: %f\n", cm);
    if(direction == l)
    {
        while(gmpc(0)<cm-26)
        {
            motor(0,50);
            motor(3,-50);
        }
    }
    if (direction == r)
    {
        cmpc(3);
        while(gmpc(3)<cm-26)
        {
            motor(0,-50);
            motor(3,50);
        }
    }

}
void pivot(int angle, int motor1)
{
    double a90 = 2160;
    double mult = angle/90;
    double cm = a90*mult;
    cmpc(0);
    if(motor1 == 0)
    {
        while(gmpc(0)<cm-26)
        {
            motor(0,50);
            motor(3,0);
        }
    }
    if(motor1==3)
    {
        cmpc(3);
        while(gmpc(3)<cm-26)
        {
            motor(0,0);
            motor(3,50);
        }
    }
        
}