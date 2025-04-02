#include <kipr/wombat.h>
void SSU(int port, int time, int final);
int thresh0 = 3600;
int thresh1 = 3600;
void drive(int distance, int speed);
void driveb(int distance, int speed);
void L90();
void R90();
void PL90();
void L45();
int adj = 4.25;
int main()
{	shut_down_in(119);
    SSU(0, 1600, 2040);//up
    cmpc(1);
    while(gmpc(1)<3000)//close a lil bit at start
    {
        motor(1,80);
    }
    freeze(1);
    msleep(800);
   	drive(203, 80);//go forward 203 ticks
    cmpc(3);
    while(gmpc(3)<3542)//turn 3542 ticks
    {
        motor(0,0);
        motor(3,70);
    }
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
    /*while(analog(0)<thresh0 || analog(1)<thresh1)// square up
    {
        motor(0,70);
        motor(3,69);
        if(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,1);
            motor(3,30);
        }
        if(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,31);
            motor(3,0);
        }
    }
    while(analog(0)>thresh0 || analog(1)>thresh1)// square up
    {
        motor(0,70);
        motor(3,69);
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
    /*printf("hi");
    while(analog(0)<thresh0)// line follow until left analog sees black
    {
        if(analog(1)<thresh1)
        {
            motor(3, 10);
            motor(0, 94);
        }
        else if(analog(1)>thresh1)
        {
            motor(0, 10);
            motor(3,80);
        }
    }*/
    while(analog(1)<thresh0)//localize analog 1 with vertical black line next to start box
    {
        motor(0,100);
        motor(3,0);
    }
    drive(300, 100);
    while(analog(0)<thresh0 || analog(1)<thresh1)// square up
    {
        motor(0,70);
        motor(3,69);
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
    printf("hello");
    motor(0,0);// turn right a lil bit
    motor(3,20);
    msleep(600);
    /*while(analog(0)>thresh0 || analog(1)>thresh1)
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
    }
    while(analog(0)<thresh0 || analog(1)<thresh1)// square up
    {
        motor(0,-70);
        motor(3,-69);
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
    }*/
    drive(400, 100);//forward 400 ticks
    cmpc(0);
    while(gmpc(0)<3700)// line follow for 3700 ticks
    {
        if(analog(1)<thresh0)
        {
            motor(3, 94);
            motor(0, 10);
        }
        else if(analog(1)>thresh0)
        {
            motor(0, 80);
            motor(3,10);
        }
    }
    driveb(1000, 80);
    freeze(0);
    freeze(3);
    SSU(0, 1600, 990);
    motor(0,30);
    motor(3,0);
    msleep(500);
    freeze(0);
    freeze(3);
    while(digital(0) == 0)
    {
        motor(1,100);
    }
    freeze(1);
    /*int currently = gmpc(1);
    while(gmpc(1)<(currently+2500))
    {
        motor(1,80);
    }*/
    freeze(1);
    motor(0,-30);
    motor(3,0);
    msleep(500);
    freeze(0);
    freeze(3);
    
    SSU(0, 1600, 1690);
    while(analog(0)<thresh0)
    {
        if(analog(1)<thresh0)
        {
            motor(3, 94);
            motor(0, 80);
        }
        else if(analog(1)>thresh0)
        {
            motor(0, 80);
            motor(3,70);
        }
    }
	driveb(780, 80);
    R90();
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,70);
        motor(3,69);
        if(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,30);
            motor(3,1);
        }
        if(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,1);
            motor(3,30);
        }
    }
    drive(500,80);
    freeze(0);
    freeze(3);
    SSU(0,1600,1300);
    motor(3,30);
    motor(0,-30);
    msleep(200);
    drive(200,40);
    while(digital(1)==0)
    {
        motor(1,-100);
    }
    freeze(1);
    SSU(0,1600,1690);
    driveb(400,80);
    //
    while(analog(0)<thresh0 || analog(1)<thresh1)// square up
    {
        motor(0,-70);
        motor(3,-69);
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
    double times = seconds();
    while(analog(0)>thresh0 || analog(1)>thresh1)// square up
    {
        motor(0,-70);
        motor(3,-69);
        if(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,-1);
            motor(3,-30);
        }
        if(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,-31);
            motor(3,0);
        }
        if(seconds()-times>1.3)
        {
            printf("fail safe activated");
            break;
        }
    }
    L90();
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,70);
        motor(3,69);
        if(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,30);
            motor(3,1);
        }
        if(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,1);
            motor(3,30);
        }
    }
    while(analog(0)>thresh0 || analog(1)>thresh1)
    {
        motor(0,70);
        motor(3,69);
        if(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,30);
            motor(3,1);
        }
        if(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,1);
            motor(3,30);
        }
    }
    driveb(1800,80);
    L90();
    drive(750,80);
    driveb(800,80);
    /*R90();
    cmpc(0);
    while(gmpc(0)>-120)
    {
        motor(0,-50);
        motor(3,50);
    }
    driveb(2200,80);
    cmpc(3);
    while(gmpc(3)>-25)
    {
        motor(0,50);
        motor(3,-50);
    }*/
    
    freeze(0);
    freeze(3);
    SSU(0, 1600, 1100);
    drive(1000, 50);
    driveb(500,50);
    //motor(3,20);
    //motor(0,-20);
    //msleep(400);
    freeze(0);
    freeze(3);
    //SSU(0, 1300, 700);
    cmpc(1);
    while(gmpc(1)<11245)
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
    SSU(0, 8000, 1690);
    L90();
    freeze(0);
    freeze(3);
    //msleep(5000);
    cmpc(0);
    while(gmpc(0)<925)
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
    SSU(0,2500,1100);
    while(gmpc(1)>0)
    {
        motor(1,-80);
    }
    freeze(1);
    motor(0,-20);
    motor(3,20);
    msleep(700);
    freeze(0);
    freeze(3);
    SSU(0,5000,1690);
    SSU(0,1600,1690);
    driveb(400, 80);
    while(analog(0)<thresh0 || analog(1)<thresh1)// square up
    {
        motor(0,-70);
        motor(3,-69);
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
    //drive(300, 80);
    drive(1400,50);
    cmpc(0);
    while(gmpc(0)<650)
    {
        motor(0,50);
        motor(3,-50);
    }
    printf("cont");
    cmpc(0);
    /*while(gmpc(0)<500)
    {
        motor(0,50);
        motor(3,0);
    }*/
    while(analog(1)<thresh1)
    {
        motor(0,-80);
        motor(3,-80);
    }
    while(analog(0)<thresh0)
    {
        if(analog(1)<thresh0)
        {
            motor(3, 94);
            motor(0, 10);
        }
        else if(analog(1)>thresh0)
        {
            motor(0, 80);
            motor(3,10);
        }
    }
    drive(500,80);
    motor(0,100);
    motor(3,0);
    msleep(1000);
    motor(0,-100);
    motor(3,0);
    msleep(1000);
    while(gmpc(0)<4700)// line follow for 3700 ticks
    {
        if(analog(1)<thresh0)
        {
            motor(3, 94);
            motor(0, 10);
        }
        else if(analog(1)>thresh0)
        {
            motor(0, 80);
            motor(3,10);
        }
    }
    driveb(1000, 80);
    freeze(0);
    freeze(3);
    SSU(0, 1600, 990);
    motor(0,30);
    motor(3,0);
    msleep(500);
    freeze(0);
    freeze(3);
    while(digital(0) == 0)
    {
        motor(1,80);
    }
    freeze(1);
    /*int currently = gmpc(1);
    while(gmpc(1)<(currently+2500))
    {
        motor(1,80);
    }*/
    freeze(1);
    motor(0,-30);
    motor(3,0);
    msleep(500);
    freeze(0);
    freeze(3);
    
    SSU(0, 1600, 1690);
    while(analog(0)<thresh0)
    {
        while(analog(1)<thresh1)
        {
            motor(0,-80);
            motor(3,0);
        }
        while(analog(1)>thresh1)
        {
            motor(3,-80);
            motor(0,0);
        }
    }
    R90();
    drive(1750, 80);
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