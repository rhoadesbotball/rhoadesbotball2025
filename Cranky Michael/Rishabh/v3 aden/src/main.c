#include <kipr/wombat.h>
#include <stdbool.h>
void SSU(int port, int time, int final);
int thresh0 = 2400;
int thresh1 = 2400;
void drive(int distance, int speed);
void driveb(int distance, int speed);
void L90();
void R90();
void PL90();
void L45();
void up();
int adj = 4.25;
bool failsafe = false;
int main()
{	
    // PART 1!!! start and getting into position to pick up poms
    //wait_for_light(5);// wait for light at analog port 5
    shut_down_in(119);// stop after 119 seconds
    SSU(0, 400, 2040);//up
    cmpc(1);
    while(gmpc(1)<3000)//close a lil bit at start
    {
        motor(1,100);
    }
    freeze(1);
    msleep(1800);//wait for other robot
    drive(203, 80);//go forward 203 ticks. Get into position
    cmpc(3);
    while(gmpc(3)<3542)//turn 3542 ticks. 135 degree turn.
    {
        motor(0,0);
        motor(3,100);
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
    while(analog(1)<thresh0)//localize analog 1 with vertical black line next to start box(drink line?)
    {
        motor(0,100);
        motor(3,0);
    }
    drive(300, 100);// drive forward a little
    while(analog(0)<thresh0 || analog(1)<thresh1)// square up
    {
        motor(0,100);
        motor(3,99);
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
    driveb(1000, 100);// backward 1000 ticks
    freeze(0);
    freeze(3);
    SSU(0, 700, 990);// down with servo 0
    motor(0,30);//pivot with motor 0
    motor(3,0);
    msleep(500);
    freeze(0);
    freeze(3);
    while(digital(0) == 0)// close claw until fully closed. Around 30 sec. point and is picking up poms //PICK UP POMS!!!!!
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
    // PART 2!!!! GETTING INTO POSITION TO DROP POMS AND DROP THEM.
    motor(0,-30);//pivot with motor 0
    motor(3,0);
    msleep(500);
    freeze(0);
    freeze(3);

    SSU(0, 1000, 1690);// go up with servo 0
    while(analog(0)<thresh0)// line follow until analog 0 senses black
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
    driveb(780, 100);// back 780 ticks
    R90();// take an exact 90 degree turn
    while(analog(0)<thresh0 || analog(1)<thresh1)// localize with line parralel and next to the trays/
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
    drive(500,100);// drive 500 ticks.
    freeze(0);
    freeze(3);
    SSU(0,600,1300);// into position to drop poms
    motor(3,30);
    motor(0,-30);
    msleep(200);
    drive(200,40);
    while(digital(1)==0)// open claw fully and score 15 pts. Maybe around the 1 min mark
    {
        motor(1,-100);
    }
    //PART 3!!!!! GETTING INTO POSITION TO PICK UP BOTTLES
    freeze(1);
    SSU(0,600,1690);// lift up
    driveb(400,80);// go back
    //
    while(analog(0)<thresh0 || analog(1)<thresh1)// backward square up
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
    L90();// perfect 90 degree turn
    cmpc(0);
    while(gmpc(0)<150)
    {
        motor(0,50);
        motor(3,-50);
    }
    while(analog(0)<thresh0 || analog(1)<thresh1)// square up
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
    driveb(1500,80);// drive back
    L90();
    drive(820,80);
    driveb(750,80);
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
    driveb(450,50);
    //motor(3,20);
    //motor(0,-20);
    //msleep(400);
    freeze(0);
    freeze(3);
    //SSU(0, 1300, 700);
    cmpc(1);
    // PART 4!!!!! GRABBING, PICKING UP, AND DROPPING THE WATER BOTTLES!
    while(gmpc(1)<11245)//pick up bottles. around 1:30 mark
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
    SSU(0,3390,1400);
    //add threading here
    thread servo_thread;
    servo_thread = thread_create(up);
    thread_start(servo_thread);
    L90();
    freeze(0);
    freeze(3);
    //msleep(5000);
    cmpc(0);
    while(gmpc(0)<750)
    {
        motor(0,50);
        motor(3,-50);
    }
    drive(3200, 80);
    motor(0,40);
    motor(3,0);
    msleep(1700);
    thread_wait(servo_thread);
    thread_destroy(servo_thread);
    freeze(0);
    freeze(3);
    SSU(0,1600,1100);
    while(gmpc(1)>0)// dropping water bottles. 360 pts. scored! NEXT PART RUNNING UNTIL AHRAN'S ROBOT DROPS! 
    {
        motor(1,-100);
    }
    // anything after here may not run due to shut_down_in.
    freeze(1);
    motor(0,-20);
    motor(3,20);
    msleep(700);
    freeze(0);
    freeze(3);
    SSU(0,2500,1690);
    SSU(0,1600,1690);
    driveb(400, 80);
    while(analog(0)<thresh0 || analog(1)<thresh1)// square up
    {
        motor(0,-100);
        motor(3,-99);
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
    drive(1400,100);
    cmpc(0);
    while(gmpc(0)<650)
    {
        motor(0,100);
        motor(3,-100);
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
        motor(0,-100);
        motor(3,-100);
    }
    while(analog(0)<thresh0)
    {
        if(analog(1)<thresh0)
        {
            motor(3, 100);
            motor(0, 10);
        }
        else if(analog(1)>thresh0)
        {
            motor(0, 100);
            motor(3,10);
        }
    }
    drive(500,100);
    motor(0,100);
    motor(3,0);
    msleep(1000);
    motor(0,-100);
    motor(3,0);
    msleep(1000);
    while(gmpc(0)<4200)// line follow for 3700 ticks
    {
        if(analog(1)<thresh0)
        {
            motor(3, 100);
            motor(0, 70);
        }
        else if(analog(1)>thresh0)
        {
            motor(0, 100);
            motor(3,70);
        }
    }

    driveb(1000, 100);
    freeze(0);
    freeze(3);
    SSU(0, 700, 990);
    motor(0,100);
    motor(3,100);
    msleep(3000);
    motor(3,100);
    motor(0,0);
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
//functions
void SSU(int port, int time, int final)// servo stepper moves servos
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
void up()
{
    SSU(0, 4000, 1690);
}
void SSUS(int port, int time, int final)// 1st Version Servo Stepper. USE IN CASE OF NEED IN SHAKEY SHAKEY
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
void drive(int distance, int speed)// drive forward using ticks and speed
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
void driveb(int distance, int speed)// drive backwards using ticks and speed
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

void L90()// perfect left 90 degree spin
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
void R90()// perfect right 90 degree spin
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
void PL90()// perfect left 90 degree pivot
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
void L45()// perfect left 45 degree spin
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