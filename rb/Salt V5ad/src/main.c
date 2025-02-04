#include <kipr/wombat.h>
#include<stdbool.h>
//combine what
void SSU(int port, int speed, int final);
int i;
void dig(double time);
void dignv(double time);
bool try1;
double timerecord1;
bool try2;
bool try3;
void digf(double time);
int main()
{	
    wait_for_light(5);
    shut_down_in(119);
    SSU(1, 1500, 430);
    SSU(2, 1500, 20);
    motor(0,76);
    motor(3,-75);
    msleep(1000);

    motor(0,75.15);
    motor(3,75);
    msleep(150);
    
    int thresh0 = 3800;
    int thresh1 = 3800;
    printf("%d\n", thresh0);
    printf("%d\n", thresh1);
    while(analog(0)>thresh0 || analog(1)>thresh1)
    {
        motor(0,70.15);
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
        motor(0,70.15);
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
        motor(0,70.15);
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
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,70.15);
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
    double stay = seconds();
    dig(3.5);
    double hey = seconds() - stay;
    printf("(%f,%d)", hey);
    printf("hello\n");
    motor(0,-75);
    motor(3,-75);
    msleep(1350);
    motor(3,75);
    motor(0,0);
    msleep(2100);
    dignv(1.2);
    motor(0,-75);
    motor(3,-75);
    msleep(667);
    motor(3,0);
    motor(0,37.5);
    msleep(3900);
    dig(1.2);
    motor(0, -71);
    motor(3,-70);
    msleep(175);
    freeze(0);
    freeze(3);
    SSU(1, 1500, 80);
    motor(0,-34);
    motor(3,-30);
    msleep(1000);
    motor(0, -34);
    motor(3, -30);
    msleep(1000);
    double timerecord = seconds();
    bool try = true;
    while(try == true)
    {
        while(analog(0)<thresh0 || analog(1)<thresh1)
        {
            motor(0,-69);
            motor(3,-65);
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
        if(seconds() - timerecord <= 1)
        {
            printf("urmommington smythe\n");
            thresh0 += 100;
            thresh1 += 100;
        }
        else
        {
            try = false;
        }
    }
    thresh0 = 3800;
    thresh1 = 3800;
    motor(0,44);
    motor(3,40);
    msleep(100);
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,-69);
        motor(3,-65);
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
    freeze(0);
    freeze(3);
    SSU(1, 1000, 400);
    motor(0, -76);
    motor(3, 0);
    msleep(3985);
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,-63);
        motor(3,-70);
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
    freeze(0);
    freeze(3);
    SSU(2, 2000, 1056);
    motor(0, 74);
    motor(3,71);
    msleep(300);
    freeze(0);
    freeze(3);
    SSU(2, 250, 1006);
    motor(0,33);
    motor(3,31);
    msleep(1000);
    freeze(0);
    freeze(3);
    SSU(2, 250, 976);
    motor(0, 33);
    motor(3, 30);
    msleep(1000);
    freeze(0);
    freeze(3);
    SSU(2, 250, 946);
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
    freeze(0);
    freeze(3);
    SSU(2, 500, 500);
    motor(0, 71.15);
    motor(3, 71);
    msleep(800);
    motor(0, 0);
    freeze(0);
    freeze(3);
    SSU(2,500,946);
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,-71);
        motor(3,-70);
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
    while(analog(0)>thresh0 || analog(1)>thresh1)
    {
        motor(0,-71);
        motor(3,-70);
        while(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,-1);
            motor(3,-30);
        }
        while(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,-31);
            motor(3,0);
        }
    }
    // WORK IN PROGRESS
    freeze(0);
    freeze(3);
    SSU(2, 1000, 20);
    motor(0,-75);
    motor(3,75);
    msleep(1415);
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

    printf("hi");
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
    dignv(4);
    motor(0, -74);
    motor(3,-70);
    msleep(400);
    freeze(0);
    freeze(3);
    SSU(1, 1500, 50);
    motor(0,-34);
    motor(3,-30);
    msleep(1000);
    motor(0, -34);
    motor(3, -30);
    msleep(1000);
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,-71);
        motor(3,-70);
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
    freeze(0);
    freeze(3);
    SSU(1, 1500, 400);
    while(analog(0)>thresh0 || analog(1)>thresh1)
    {
        motor(0,-70);
        motor(3,-71);
        while(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,-1);
            motor(3,-30);
        }
        while(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,-31);
            motor(3,0);
        }
    }
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,-70);
        motor(3,-72);
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
    while(analog(0)>thresh0 || analog(1)>thresh1)
    {
        motor(0,-70);
        motor(3,-72);
        while(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,-1);
            motor(3,-30);
        }
        while(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,-31);
            motor(3,0);
        }
    }
    freeze(0);
    freeze(3);
    // code comb
    SSU(1, 1500, 430);
    SSU(2, 1500, 20);
    SSU(3, 1500, 20);
    thresh0 = 3400;
    thresh1 = 3400;
    try2 = true;
    motor(0,0);
    motor(3,0);
    msleep(5000);
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
    msleep(280);
    motor(0,0);
    motor(3,-71);
    msleep(2245);

    motor(0,71.15);
    motor(3,71);
    msleep(450);
    freeze(0);
    freeze(3);
    msleep(50);
    SSU(2, 1500, 875);
    motor(0,-71.15);
    motor(3,-71);
    msleep(850);
    freeze(0);
    freeze(3);
    SSU(3, 1500, 1600);
    SSU(2, 1000, 20);
    motor(0,71.15);
    motor(3,71);
    msleep(500);
    while(analog(0)<thresh0)
    {
        motor(0,-71);
        motor(3,0);
    }
    motor(0,71.5);
    motor(3,90);
    msleep(125);
    motor(0,0);
    motor(3,-71);
    msleep(700);
    freeze(0);
    freeze(3);
    SSU(2,1000,885);
    motor(0,0);
    motor(3,-71);
    msleep(1100);
    freeze(0);
    freeze(3);
    SSU(3,1500,406);
    SSU(2, 1000, 20);
    
    /*bool try9 = true;
    while(try9 == true)
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
            try9 = false;
        }
    }
    motor(0,74);
    motor(3,71);
    msleep(880);
    motor(0,0);
    motor(3,-71);
    msleep(2245);
	SSU(2, 1500, 875);
    motor(0,-71.15);
    motor(3,-71);
    msleep(850);
    freeze(0);
    freeze(3);
    SSU(3, 1500, 1600);
    SSU(2, 1000, 20);
    motor(0,71.15);
    motor(3,71);
    msleep(500);
    motor(0, 70);
    motor(3,-70);
    msleep(1127);*/
    
    while(digital(0)==0)
    {
        if(analog(0)<thresh0)
        {
            motor(0,60);
            motor(3,100);
        }
        if(analog(0)>thresh0)
        {
            motor(0,100);
            motor(3,64);
        }
    }
    digf(1);
    motor(0,-74);
    motor(3,-71);
    msleep(1000);
    motor(0,0);
    motor(3,-71);
    msleep(2000);

    digf(5);
    motor(0,-79);
    motor(3,79);
    msleep(1150);
    motor(0,79);
    motor(3,75);
    msleep(500);
    freeze(0);
    freeze(3);
	SSU(3, 1500, 1600);
    return 0;
}
void SS1(int port, int speed, int final)
{
    enable_servo(port);
    int pos=get_servo_position(port);
    while(pos<final)
    {
        pos+=10;
        set_servo_position(port, pos);
        msleep(10);
    }
    while(pos>final)
    {
        pos-=10;
        set_servo_position(port, pos);
        msleep(10);
    }
    disable_servo(port);
}
void digf(double time)
{
    try1 = true;
    timerecord1 = seconds();
    while(try1 == true)
    {
        if(digital(0)==0 || digital(1)==0)
        {
            motor(0,100);
            motor(3,100);
            if(digital(0)==1 && digital(1)==0)
            {
                motor(0,0);
                motor(3,30);
            }
            if(digital(0)==0 && digital(1)==1)
            {
                motor(0,30);
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
    timerecord1 = seconds();
    try3 = true;
    while(try3==true)
    {
        if(digital(0)==0 || digital(1)==0)
        {
            motor(0,100);
            motor(3,100);
            if(digital(0)==1 && digital(1)==0)
            {
                motor(0,0);
                motor(3,30);
            }
            if(digital(0)==0 && digital(1)==1)
            {
                motor(0,30);
                motor(3,0);
            }
        }
        if(seconds() - timerecord1 >= 0.001)
        {
            try3 = false;
        }


    }
}

void dignv(double time)
{
    try1 = true;
    timerecord1 = seconds();
    while(try1 == true)
    {
        if(digital(0)==0 || digital(1)==0)
        {
            motor(0,40);
            motor(3,40);
            if(digital(0)==1 && digital(1)==0)
            {
                motor(0,0);
                motor(3,30);
            }
            if(digital(0)==0 && digital(1)==1)
            {
                motor(0,30);
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
    timerecord1 = seconds();
    try3 = true;
    while(try3==true)
    {
        if(digital(0)==0 || digital(1)==0)
        {
            motor(0,71);
            motor(3,70);
            if(digital(0)==1 && digital(1)==0)
            {
                motor(0,0);
                motor(3,30);
            }
            if(digital(0)==0 && digital(1)==1)
            {
                motor(0,30);
                motor(3,0);
            }
        }
        if(seconds() - timerecord1 >= 1)
        {
            try3 = false;
        }


    }
}
void dig(double time)
{
    try1 = true;
    timerecord1 = seconds();
    while(try1 == true)
    {
        if(digital(0)==0 || digital(1)==0)
        {
            motor(0,70.5);
            motor(3,70);
            if(digital(0)==1 && digital(1)==0)
            {
                motor(0,0);
                motor(3,30);
            }
            if(digital(0)==0 && digital(1)==1)
            {
                motor(0,30);
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
    timerecord1 = seconds();
    try3 = true;
    while(try3==true)
    {
        if(digital(0)==0 || digital(1)==0)
        {
            motor(0,71);
            motor(3,70);
            if(digital(0)==1 && digital(1)==0)
            {
                motor(0,0);
                motor(3,30);
            }
            if(digital(0)==0 && digital(1)==1)
            {
                motor(0,30);
                motor(3,0);
            }
        }
        if(seconds() - timerecord1 >= 0.5)
        {
            try3 = false;
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
