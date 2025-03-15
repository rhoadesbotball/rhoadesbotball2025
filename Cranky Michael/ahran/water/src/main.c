#include <kipr/wombat.h>
void SSU(int port, int time, int final);
int thresh0 = 3200;
int thresh1 = 3200;
void drive(int distance);
void driveb(int distance);
void L90();
void R90();
void PL90();
void L45();
int adj = 14;
int main()
{	
    msleep(1500);
    SSU(0, 1600, 69);
    PL90();
    /*while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,70);
        motor(3,72);
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
        motor(0,70);
        motor(3,72);
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
    }*/
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,70);
        motor(3,84);
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
        motor(0,70);
        motor(3,84);
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
    while(analog(1)<thresh1)
    {
        if(analog(0)<thresh0)
        {
            motor(3, 94);
            motor(0, 10);
        }
        else if(analog(0)>thresh0)
        {
            motor(0, 80);
            motor(3,10);
        }
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
    driveb(300);
    cmpc(3);
    while(gmpc(3)>(2600*-1) + 26)
    {
        motor(0,0);
        motor(3,-50);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
    drive(1500);
    driveb(300);
    freeze(0);
    freeze(3);
    SSU(0, 1000, 680);
    for(int i = 0; i<11; i++)
    {
        motor(3, 100);
        motor(0,100);
        msleep(100);
        motor(0, -100);
        motor(3, -100);
        msleep(100);
    }
    drive(100);
    freeze(0);
    freeze(3);
    SSU(0, 100, 850);
    for(int i = 0; i<11; i++)
    {
        motor(3, 100);
        motor(0,100);
        msleep(100);
        motor(0, -100);
        motor(3, -100);
        msleep(100);
    }
    freeze(0);
    freeze(3);
    msleep(10);
    SSU(0, 1600, 250);
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,-90);
        motor(3,-84);
        while(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,-1);
            motor(3,-30);
        }
        while(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,-31);
            motor(3,0);
        }
    }
    L90();
    L45();
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,70);
        motor(3,84);
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
    
    drive(1500);
    SSU(0,680,1000);
    return 0;
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
void SSUS(int port, int time, int final)
{
    enable_servo(port);
    int pos = get_servo_position(port);
    double mssleep;
    int distance;
    if(pos>final)
    {
        distance = pos - final;
        mssleep = time/distance;
    }
    else if(pos<final)
    {
        distance = final - pos;
        mssleep = time/distance;
    }
    while(pos<final)
    {
        freeze(0);
        freeze(3);
        pos+=1;
        set_servo_position(port, pos);
        msleep(mssleep);
        motor(3,80);
        motor(0,0);
        msleep(1);
        motor(0,80);
        motor(3,0);
        msleep(1);

    }
    while(pos>final)
    {
        freeze(0);
        freeze(3);
        pos-=1;
        set_servo_position(port, pos);
        msleep(mssleep);
        motor(3,80);
        motor(0,-66);
        msleep(1);
        motor(0,66);
        motor(3,-80);
        msleep(1);

    }
    disable_servo(port);
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
    while(gmpc(0)>(1210*-1) + 26)
    {
        motor(0,-50);
        motor(3,50);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
}
void PL90()
{
    cmpc(3);
    while(gmpc(3)<3750-26)
    {
        motor(3,50);
        motor(0,0);
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}
void L45()
{
    cmpc(0);
    while(gmpc(0)<600 - 26)
    {
        motor(0,50);
        motor(3,-50);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
}