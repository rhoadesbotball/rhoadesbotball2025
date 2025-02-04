#include <kipr/wombat.h>
int r=0;
int l=1;

void mec(int u,int v, int w, int x, int sleep)
{
    motor(0,u);
    motor(3,x);
    motor(1,v);
    motor(2,w);
    msleep(sleep);
}
void strafe(int direction, int speed, int duration)
{
    while (direction==r)
    {
        mec(-speed,speed,-speed,speed,duration);
    }
    while (direction==l)
    {
        mec(speed,-speed,speed,-speed,duration);
    }

}
void forward(int time,int speed)
{
    motor(0,speed);
    motor(1,speed);
    motor(2,speed);
    motor(3,speed);
    msleep(time);
}
void backward(int timeback,int speedback)
{
    motor(0,-speedback);
    motor(1,-speedback);
    motor(2,-speedback);
    motor(3,-speedback);
    msleep(timeback);
}
void servo(int port,int time, int final)
{
    enable_servo(port);
    int pos=get_servo_position(port);
    while(pos>final)
    {
        pos=pos-10;
        set_servo_position(port,pos);
        msleep(time);


    }
    while(pos<final)
    {
        pos=pos+10;
        set_servo_position(port,pos);
        msleep(time);

    }
    disable_servo(port);
}
void localize()
{
    while(analog(1)<3700 || analog(0)<3700)
    {
        if(analog(1)<3700 && analog(0)>3700)
        {
            motor(0,0);
            motor(3,30);
            motor(2,30);
            motor(1,0);
        }
        else if(analog(1)>3700 && analog(0)<3700)
        {
            motor(3,0);
            motor(0,30);
            motor(1,30);
            motor(2,0);



        }
        else
        {
            motor(0,30);
            motor(3,30);
            motor(2,30);
            motor(1,30);


        }

    }
    while(analog(1)>3700 || analog(0)>3700)
    {
        if(analog(1)>3700 && analog(0)<3700)
        {

            motor(0,0);
            motor(3,30);
            motor(2,30);
            motor(1,0);
        }
        else if(analog(1)<3700 && analog(0)>3700)
        {
            motor(1,30);
            motor(2,0);
            motor(3,0);
            motor(0,30);

        }
        else
        {
            motor(3,30);
            motor(2,30);
            motor(1,30);
            motor(0,30);
        }
    }

}
void locback()
{
    while(analog(1)<3700 || analog(0)<3700)
    {
        if(analog(1)<3700 && analog(0)>3700)
        {
            motor(0,30);
            motor(3,30);
            motor(2,0);
            motor(1,0);
        }
        else if(analog(1)>3700 && analog(0)<3700)
        {
            motor(3,0);
            motor(0,0);
            motor(1,30);
            motor(2,30);



        }
        else
        {
            motor(0,-30);
            motor(3,-30);
            motor(2,-30);
            motor(1,-30);


        }

    }
    while(analog(1)>3700 || analog(0)>3700)
    {
        if(analog(1)>3700 && analog(0)<3700)
        {

            motor(0,30);
            motor(3,30);
            motor(2,0);
            motor(1,0);
        }
        else if(analog(1)<3700 && analog(0)>3700)
        {
            motor(1,30);
            motor(2,30);
            motor(3,0);
            motor(0,0);

        }
        else
        {
            motor(3,-30);
            motor(2,-30);
            motor(1,-30);
            motor(0,-30);
        }
    }

}    



