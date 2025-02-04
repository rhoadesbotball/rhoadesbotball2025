#include <kipr/wombat.h>
int veers=30;
void localizeA();
void localizeD();
//void ssa(int position, int port);
void straight(int velocityst, int durationst);
void spin(int velocitysp,int durationsp);
void veer(int velocityve,int durationspve);
void pivot(int velocitypi,int durationspi);
int main()
{
    enable_servos();
    set_servo_position(2,76);
    msleep(500);
    set_servo_position(1,500);
    msleep(500);
    spin(100,750);
    localizeA();
    straight(100,100);
    localizeA();
    pivot(-100,100);
    localizeD();
    straight(-100,500);
    spin(-100,800);
    localizeD();
    straight(-100,1000);
    spin(-100,865);
    spin(100,40);
    straight(100,500);
    set_servo_position(2,820);
    msleep(500);
    straight(100,500);
    set_servo_position(2,76);
    msleep(500);
    pivot(-100,2900);
    localizeA();
    straight(100,1200);
    set_servo_position(1,176);
    msleep(500);
    straight(-100,4000);
    set_servo_position(1,500);
    msleep(500);
    disable_servos();
    localizeA();
    straight(100,1500);
    spin(100,800);
    straight(100,3000);
    spin(100,800);
    veer(100,300);
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
    motor(0, velocityve+veers);
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
            motor(0,0);
            motor(3,30);
        }
        else if ((digital(1)==0) && (digital(0)==1))
        {
            motor(3,0);
            motor(0,30);
        }
        else if ((digital(1)==0) && (digital(0)==0))
        {
            motor(3,60);
            motor(0,60);
        }

        else 
        {
            motor(3,0);
            motor(0,0);
        }
    }
}

//void ssa(int position, int port);
//{
  //  while (get_servo_position(port) < position)
    //{
      //  int servoposition = get_servo_position + 5;
       // set_servo_position(port,servoposition);
       // msleep(25);
    //}  
//}      