#include <kipr/wombat.h>
double wheelC = 20.9465690178018/1500;
int r = 1;
int l = 0;
int mpc0;
int mpc3;
void mpcdrive12(int speed, int dc)// PERFECTLY STRAIGHT DRIVE WITH MOTOR POSITION COUNTER
{
    double ticks=(dc+6)/wheelC;
    printf("%f\n", ticks);
    cmpc(0);
    cmpc(3);
    while(gmpc(0)<ticks-20 || gmpc(3)<ticks-20)
    {
        if(gmpc(0)==gmpc(3))
        {
            motor(0,speed+1);
            motor(3,speed);
        }
        else if(gmpc(0)>gmpc(3))
        {
            motor(0,speed-6);
            motor(3,speed);
        }
        else if(gmpc(0)<gmpc(3))
        {
            motor(0,speed+1);
            motor(3,speed-7);
        }
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}
void calib()
{
    cmpc(0);
    cmpc(3);
}
void save()
{
    mpc0 = gmpc(0);
    mpc3 = gmpc(3);
}
void align()
{
    while(gmpc(0)<gmpc(3))
    {
        motor(0,20);
        motor(3,-1);
    }
    while(gmpc(0)>gmpc(3))
    {
        motor(0,1);
        motor(3,20);
    }
}
void plf(int speed, int direction, int tick, int difference)
{
    cmpc(0);
    while(gmpc(0)<tick)
    {
        if(direction == 1)
        {
            if(analog(0)<3400)
            {
                motor(3,speed);
                motor(0,speed-difference);
            }

            else
            {
                motor(3,speed-difference);
                motor(0,speed);
            }
        }
        if(direction == 0)
        {
            if(analog(0)<3400)
            {
                motor(3,speed-difference);
                motor(0,speed);
            }

            else
            {
                motor(3,speed);
                motor(0,speed-difference);  
            }
        }
    }
}
void alignws()
{
    while(gmpc(0)+mpc0<gmpc(3)+mpc3)
    {
        motor(0,20);
        motor(3,-1);
    }
    while(gmpc(0)+mpc0>gmpc(3)+mpc3)
    {
        motor(0,1);
        motor(3,20);
    }
} 
void compassdrive(double speed, double time)
{
    set_compass_params(1.583000, -2.482000, -58.319000, 0.411457, -0.0090300, 1.081340, 1.169338);
    int print = get_compass_angle();
    printf("Hi %d\n",print);
    motor(3,50);
    msleep(1500);
    print = get_compass_angle();
    printf("Hi %d\n",print);
}
