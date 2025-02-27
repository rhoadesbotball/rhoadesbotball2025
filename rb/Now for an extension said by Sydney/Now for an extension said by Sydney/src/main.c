#include <kipr/wombat.h>
#include<stdbool.h>
void SSU(int port, int speed, int final);
int i;
void dig(double time);
bool try1;
bool try2;
double timerecord1;
int main()
{
    SSU(1, 1500, 430);
    SSU(2, 1500, 20);
    int thresh0 = 3000;
    int thresh1 = 3000;
    try2 = true;
    while(analog(0)>thresh0 || analog(1)>thresh1)
    {
        motor(0,74);
        motor(3,70);
        while(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,1);
            motor(3,30);
        }
        while(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,31);
            motor(3,0);
        }
    }
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,74);
        motor(3,70);
        while(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,1);
            motor(3,30);
        }
        while(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,31);
            motor(3,0);
        }
    }
    motor(0,74);
    motor(3,71);
    msleep(350);
    while(try2 == true)
    {
        if(analog(1)<thresh1)
        {
            motor(0,75);
            motor(3,25);
        }
        if(analog(1)>thresh1)
        {
            motor(0,29);
            motor(3,75);
        }
        if(analog(0)>thresh0)
        {
            try2 = false;
        }
    }
    motor(0,0);
    motor(3,-71);
    msleep(1955);
    freeze(0);
    freeze(3);
   	msleep(50);
    SSU(2, 1500, 885);
    motor(0,-74);
    motor(3,-71);
    msleep(250);
    return 0;
}
void dig(double time)
{
    try1 = true;
    timerecord1 = seconds();
    while(try1 == true)
    {
        if(digital(0)==0 || digital(9)==0)
        {
            motor(0,74);
            motor(3,70);
            if(digital(0)==1 && digital(9)==0)
            {
                motor(0,0);
                motor(3,60);
            }
            if(digital(0)==0 && digital(9)==1)
            {
                motor(0,60);
                motor(3,0);
            }
        }
        if(seconds() - timerecord1 >= time)
        {
            printf("hey dummy try again stpid");
            motor(0,-71);
            motor(3,-70);
            msleep(300);
            try1=false;
        }

    }
    while(digital(0)==0 || digital(9)==0)
    {
        motor(0,71);
        motor(3,70);
        while(digital(0)==1 && digital(9)==0)
        {
            motor(0,0);
            motor(3,60);
        }
        while(digital(0)==0 && digital(9)==1)
        {
            motor(0,60);
            motor(3,0);
        }
    }
}

void SSU(int port, int time, int final)
{
    enable_servo(port);
    int pos = get_servo_position(port);
    double mssleep;
    int distance;
    if(pos>final){
        distance = pos - final;
        mssleep = time/distance;
    }
    else if(pos<final){
        distance = final - pos;
        mssleep = time/distance;
    }
    while(pos<final)
    {
        pos+=1;
        set_servo_position(port, pos);
        msleep(mssleep);
    }
    while(pos>final)
    {
        pos-=1;
        set_servo_position(port, pos);
        msleep(mssleep);
    }
    disable_servo(port);
}
