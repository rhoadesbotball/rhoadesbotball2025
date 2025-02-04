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
    SSU(3, 1500, 20);
    int thresh0 = 3400;
    int thresh1 = 3400;
    try2 = true;
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,71);
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
    while(analog(0)>thresh0 || analog(1)>thresh1)
    {
        motor(0,71);
        motor(3,70);
        while(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,1);
            motor(3,30);
        }
        while(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,31);
            motor(3,0);
        }
    }
    motor(0,71);
    motor(3,71);
    msleep(200);
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
    motor(0,74);
    motor(3,71);
    msleep(500);
    motor(0,0);
    motor(3,-71);
    msleep(2245);

    motor(0,71.15);
    motor(3,71);
    msleep(400);
    freeze(0);
    freeze(3);
    msleep(50);
    SSU(2, 1500, 885);
    motor(0,-71.15);
    motor(3,-71);
    msleep(850);
    freeze(0);
    freeze(3);
    SSU(3, 1500, 1600);
    SSU(2, 1000, 20);
    motor(0,71.15);
    motor(3,71);
    msleep(550);
    while(analog(0)<thresh0)
    {
        motor(0,-71);
        motor(3,0);
    }
    motor(0,-71.5);
    motor(3,-100);
    msleep(10);
    motor(0,0);
    motor(3,-71);
    msleep(700);
    freeze(0);
    freeze(3);
    SSU(2,1000,885);
    motor(0,0);
    motor(3,-71);
    msleep(900);
    freeze(0);
    freeze(3);
    SSU(3,1500,406);
    SSU(2, 1000, 20);
    while(digital(0)==0)
    {
        if(analog(0)<thresh0)
        {
            motor(0,25);
            motor(3,75);
        }
        if(analog(0)>thresh0)
        {
            motor(0,75);
            motor(3,29);
        }
    }
    dig(1);
    motor(0,-74);
    motor(3,-71);
    msleep(1000);
    motor(0,0);
    motor(3,-71);
    msleep(2000);

    dig(2);
    motor(0,-79);
    motor(3,0);
    msleep(1500);
    motor(0,79);
    motor(3,75);
    msleep(100);
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
