#include <kipr/wombat.h>
#include <rhoadesbotball.h> 
void localizeA();
void localizeD();
void straight(int velocityst, int durationst);
void spin(int velocitysp,int durationsp);
void veer(int velocityve,int durationspve);
void pivot(int velocitypi,int durationspi);
int main()
{
    localizeA();
    straight(100,100);
    localizeA();
    localizeD();


    return 0;
}
void localizeA()
{
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            motor(0,0);
            motor(3,30);
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            motor(3,0);
            motor(0,30);
        }
        else
        {
            motor(3,30);
            motor(0,30);
        }
    }while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            motor(0,0);
            motor(3,30);
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            motor(3,0);
            motor(0,30);
        }
        else
        {
            motor(3,30);
            motor(0,30);
        }
    }
    while((analog(1)>3350) || (analog(0)>3350))
    {
        if ((analog(1)>3350) && (analog(0)<3350))
        {
            motor(0,0);
            motor(3,30);
        }
        else if ((analog(1)<3350) && (analog(0)>3350))
        {
            motor(3,0);
            motor(0,30);
        }
        else
        {
            motor(3,30);
            motor(0,30);
        }
    }
}
void straight(int velocityst,int durationst){
    motor(0, velocityst); 
    motor(3, velocityst);
    msleep(durationst);
}
void spin(int velocitysp,int durationsp){
    motor(0, velocitysp);
    motor(3, -velocitysp);
    msleep(durationsp);
}
void veer(int velocityve,int durationve){
    motor(0, velocityve+30);
    motor(3, velocityve);
    msleep(durationve);
}
void pivot(int velocitypi,int durationpi){
    motor(0, 0);
    motor(3, velocitypi);
    msleep(durationpi);
}
void localizeD()
{
    while((digital(1)==0) || (digital(0)==0))
    {
        if ((digital(1)==1) && (digital(0)==0))
        {
            mecwsleep(0,30,30,0);
        }
        else if ((digital(1)==0) && (digital(0)==1))
        {
            mecwsleep(30,0,0,30);
        }
        else if ((digital(1)==0) && (digital(0)==0))
        {
            motor(3,30);
            motor(0,30);
        }

        else 
        {
            motor(3,0);
            motor(0,0);
        }
    }
}