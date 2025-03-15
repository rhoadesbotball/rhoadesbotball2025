#include <kipr/wombat.h>
#include <mechanumwheels.h>

void mec(int fr,int fl, int br, int bl, int duration);
void strafe(int speed, int duration);
void fwd(int speed, int duration);
void veer(int speed, int plusspeed, int duration);
void spin(int speed, int duration);
int main()
{
    
    fwd(-100,2000);
    strafe(100,2000);
    fwd(100,2000);
    strafe(-100,2000); 
	

    return 0;
}

void mec(int fr,int fl, int bl, int br, int y)
{
    motor(0,fr);
    motor(3,fl);
    motor(1,bl);
    motor(2,br);
    msleep(y);
}
void fwd(int speed,int duration)
{
    mec(speed,speed,speed,speed,duration);  
}
void strafe(int speed, int duration)
{
    mec(speed,-speed,-speed,speed,duration);
}
void veer(int speed, int plusspeed, int duration)
{
    mec(speed,speed ,speed + plusspeed,speed+ plusspeed,duration);
}  

void spin(int speed, int duration)
{
    mec(speed,-speed,speed,-speed,duration);
}   







