#include <kipr/wombat.h>
void SSU(int port, int time, int final);
int thresh0 = 3200;
int thresh1 = 3200;
void drive(int distance, int speed);
void driveb(int distance, int speed);
void L90();
void R90();
void PL90();
void L45();
int adj = 1;
int main()
{
    SSU(0, 1000, 1690);
    drive(1821, 80);
    freeze(0);
    freeze(3);
    SSU(0, 1600, 1100);
    drive(1000, 50);
    driveb(500,20);
    //motor(3,20);
    //motor(0,-20);
    //msleep(400);
    freeze(0);
    freeze(3);
    //SSU(0, 1300, 700);
    cmpc(1);
    while(gmpc(1)<9545)
    {
        motor(1,80);
    }
    freeze(1);
    driveb(500, 20);
    freeze(0);
    freeze(3);
    /*freeze(1);
    SSU(0, 1300, 900);
    driveb(600, 20);
    freeze(0);
    freeze(3);
    driveb(1, 15);
    freeze(1);*/
    SSU(0, 10000, 1690);
    L90();
    cmpc(0);
    while(gmpc(0)<875)
    {
        motor(0,50);
        motor(3,-50);
    }
    drive(3200, 80);
    motor(0,40);
    motor(3,0);
    msleep(1700);
    freeze(0);
    freeze(3);
    SSU(0,5000,1100);
    while(gmpc(1)>0)
    {
        motor(1,-80);
    }
    freeze(1);
    SSU(0,1600,1690);
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
void drive(int distance, int speed)
{
    cmpc(0);
    while(gmpc(0)<distance-26)
    {
        motor(0,speed);
        motor(3,speed+adj);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
}
void driveb(int distance, int speed)
{
    cmpc(0);
    while(gmpc(0)>(distance*-1) + 26)
    {
        motor(0,-1*speed);
        motor(3,(-1*speed) + adj);
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