#include <kipr/wombat.h>
#include <alpha.h>
#include <stdio.h>
#include <stdbool.h>
bool failed = false;
int servo1;
int servoice;
void camera();
//void pvt(int wheel, int speed, int sleep)
int main()
{ 
    /*
    servox(1,1000,1200);
    servox(3,1000,6); 
    servox(2,1000,2000);


    servox(1,10000,544);

    */

    //wait(700);
    servox(0,1410,1000);
    servox(3, 130, 1000);
    //servox(2,976,1000);
    servox(1, 1940, 1000);
    servox(2, 50, 1000);
    shut_down_in(119);
    camera();
    //wait(1500);
    servox(3,1500,1000);

    loki();
    cmpc(0);
    fwd(100,1900);
    printf("%d\n",gmpc(0));
    STA(r,90);
    pvt(r,-50,600);
    pvt(l,-50,450);
    ao();
    servox(0,390,1500);
    //
    strafe(l,50,1200);

    wait(700);


    fwd(100,137.5);

    pvt(r,-100,25);
    pvt(l,-100,275);
    pvt(r,100,250);
    pvt(r, 100, 150);


    strafe(l,100,600);

    pvt(r,-100,400);
    pvt(l,-100,275);
    pvt(r,100,175);
    pvt(r,-100,75);

    //strafe(l,100,600);
    printf("hi\n");
    freeze(0);
    freeze(1);
    freeze(2);
    freeze(2);
    wait(700);
    //
    cmpc(0);
    while(gmpc(0)>-1250)
    {
        mecwsleep(-100,-100,-100,-100);
    }
    pvt(r,-50,600);
    pvt(l,-50,450);
    ao();
    servox(0,650,1000);
    servox(0,300,1000);


    while(analog(0)<thresh0)
    {
        mecwsleep(-90,90,-90,90);
    }

    ao();
    servox(0,450,1000);
    cmpc(0);
    while(gmpc(0)<400)
    {
        mecwsleep(80, -90, 70, -90);
    }
    wait(1);
    cmpc(0);
    while(gmpc(0)<275)
    {
        mecwsleep(80,-80,80,-80);
    }
    localizeA();
    cmpc(0);
    while(gmpc(0)<200)
    {
        mecwsleep(100,100,100,100);
    }
    double time = seconds();
    while(analog(0)<thresh0)
    {
        if(analog(1)<thresh1)
        {
            mecwsleep(80,0,0,80);
        }
        else if(analog(1)>thresh1)
        {
            mecwsleep(0,80,80,0);
        }
        if(seconds()-time>7.25)
        {
            printf("failed");
            failed = true;
            break;
        }
    }
    //106 close
    // 160 down
    // 2046 open
    cmpc(0);
    while(gmpc(0)>-1900)
    {
        mecwsleep(-100,-100,-100,-100);
    }
    wait(1);
    servox(1, 1900, 1500);
    servox(2, 2046, 1500);
    servox(3, 60, 1500);
    cmpc(0);
    while(gmpc(0)<1250)
    {
        mecwsleep(100,100,100,100);
    }
    wait(1);
    servox(2, 1, 500);
    cmpc(0);
    while(gmpc(0)>-950)
    {
        mecwsleep(-100,-100,-100,-100);
    }
    wait(1);
    servox(2, 2046, 500);
    double timer = seconds();
    cmpc(0);
    while(gmpc(0)<900)
    {
        mecwsleep(100,100,100,100);
    }

    wait(1);
    servox(2, 1, 500);
    cmpc(0);
    while(gmpc(0)>-970)
    {
        mecwsleep(-100,-100,-100,-100);
    }
    wait(1);
    servox(3, 2000, 2500);
    servox(0, 750, 1000);
    servox(1, servo1, 2000);
    servox(2, 2046, 1000);
    servox(0, 400, 1000);
    printf("%f\n", seconds()-timer);
    wait(1);
    servox(1, 1900, 1500);
    servox(2, 2046, 1500);
    servox(3, 30, 1500);
    cmpc(0);
    while(gmpc(0)<970)
    {
        mecwsleep(100,100,100,100);
    }
    wait(1);
    servox(2, 1, 500);
    cmpc(0);
    while(gmpc(0)>-970)
    {
        mecwsleep(-100,-100,-100,-100);
    }
    wait(1);
    servox(3, 2000, 2500);
    servox(0, 750, 1000);
    servox(1, servo1, 2000);
    servox(2, 2046, 1500);
    servox(0, 350, 2000);
    servox(0, 750, 1000);
    servox(0, 450, 1000);
    servox(1, 1900, 500);
    time = seconds();
    while(analog(0)<thresh0)
    {
        if(analog(1)<thresh1)
        {
            mecwsleep(80,0,0,80);
        }
        else if(analog(1)>thresh1)
        {
            mecwsleep(0,80,80,0);
        }
        if(seconds()-time>2.5)
        {
            printf("failed");
            failed = true;
            break;
        }
    }
    cmpc(0);
    while(gmpc(0)>-2000)
    {
        mecwsleep(-100,-100,-100,-100);
    }
    wait(1);
    servox(1, 1900, 1500);
    servox(2, 2046, 1500);
    servox(3, 30, 1500);
    cmpc(0);
    while(gmpc(0)<1400)
    {
        mecwsleep(100,100,100,100);
    }
    wait(1);
    servox(2, 1, 500);
    cmpc(0);
    while(gmpc(0)>-970)
    {
        mecwsleep(-100,-100,-100,-100);
    }
    wait(1);
    servox(2, 2046, 1000);
    cmpc(0);
    while(gmpc(0)<975)
    {
        mecwsleep(100,100,100,100);
    }
    wait(1);
    servox(2, 1, 500);
    cmpc(0);
    while(gmpc(0)>-930)
    {
        mecwsleep(-100,-100,-100,-100);
    }
    int servod;
    if(servo1 == 858)
    {
        servod = 1169;
    }
    else if(servo1 == 500)
    {
        servod = 1169;
    }
    else
    {
        servod = 858;
    }
    wait(1);
    servox(3, 2000, 2500);
    servox(0, 750, 1000);
    servox(1, servod, 2000);
    servox(2, 2046, 1500);
    servox(0, 350, 2000);
    servox(0, 750, 1000);
    while(gmpc(1)>-350)
    {
        mecwsleep(0, -100, -100, 0);
    }
    /*while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        mecwsleep(-100,-100,-100,-100);
        if(analog(0)>thresh0 && analog(1)<thresh1)
        {
            mecwsleep(0, 0, -100, 0);
        }
        else if(analog(0)<thresh0 && analog(1)>thresh1)
        {
            mecwsleep(0, 0, 0, -100);
        }
    }
    while(analog(0)>thresh0 || analog(1)>thresh1)
    {
        mecwsleep(-100,-100,-100,-100);
        if(analog(0)<thresh0 && analog(1)>thresh1)
        {
            mecwsleep(0, 0, -100, 0);
        }
        else if(analog(0)>thresh0 && analog(1)<thresh1)
        {
            mecwsleep(0, 0, 0, -100);
        }
    }*/
    locback();
    cmpc(0);
    while(gmpc(0)<1750)
    {
        mecwsleep(100,100,100,100);
    }
    STA(l,90);

    localizeA();
    cmpc(0);
    while(gmpc(0)>-1750)
    {
        mecwsleep(-100,-100,-100,-100);
    }
    cmpc(0);
    while(gmpc(0)>-800)
    {
        mecwsleep(-100, 0, -100, 0);
    }
    wait(1);
    servox(1, 890, 1000);
    servox(3, 30, 2000);
    for(int i = 0; i<5; i++)
    {
        cmpc(0);
        while(gmpc(0)<100)
        {
            mecwsleep(100,100,100,100);
        }
        cmpc(0);
        while(gmpc(0)>-100)
        {
            mecwsleep(-100,-100,-100,-100);
        }
    }
    while(gmpc(0)>-500)
    {
        mecwsleep(-80, 90, -70, 90);
    }
    wait(1);
    servox(2, 1, 2000);
    servox(3, 1500, 1500);
    servox(0, 900, 1000);
    servox(1, servoice, 2000);
    servox(3, 2046 ,1000);
    servox(2, 1000, 1500);
    cmpc(0);
    while(gmpc(0)<350)
    {
        mecwsleep(100,100,100,100);
    }
    wait(1);
    servox(2,2046, 1000);
    servox(3, 30, 2000);
    servox(1, 890, 1000);
    for(int i = 0; i<5; i++)
    {
        cmpc(0);
        while(gmpc(0)<100)
        {
            mecwsleep(100,100,100,100);
        }
        cmpc(0);
        while(gmpc(0)>-100)
        {
            mecwsleep(-100,-100,-100,-100);
        }
    }
    while(gmpc(0)>-500)
    {
        mecwsleep(-80, 90, -70, 90);
    }
    wait(1);
    servox(2, 1, 2000);
    servox(3, 1500, 1500);
    servox(0, 900, 1000);
    servox(1, servoice, 2000);
    servox(3, 2046 , 1000);
    servox(2, 1000, 1500);
    strafe(l, 100, 2700);
    wait(1);
    servox(0, 350, 1000);
    
    /*strafe(l, 100, 700);
    cmpc(0);
    while(gmpc(0)<500)
    {
        mecwsleep(100, 100, 100, 100);
    }
    wait(1);
    servox(2,2046, 1000);
    servox(3, 30, 2000);
    servox(1, 890, 1000);
    for(int i = 0; i<5; i++)
    {
        cmpc(0);
        while(gmpc(0)<100)
        {
            mecwsleep(100,100,100,100);
        }
        cmpc(0);
        while(gmpc(0)>-100)
        {
            mecwsleep(-100,-100,-100,-100);
        }
    }
    wait(1);
    servox(2, 1, 2000);
    servox(3, 1500, 1500);
    servox(0, 800, 1000);
    servox(1, servoice, 2000);
    servox(3, 2046 , 1000);
    servox(2, 1000, 1500);*/


    /*loki();
    double time1 = seconds();
    while(seconds() - time1 < 8)
    {
        while(analog(1)<thresh1)
        {
            mecwsleep(50, 0, 0, 50);
        }
        while(analog(1)>thresh1)
        {
            mecwsleep(0,50,50,0);
        }
    }
    pvt(r, 50, 600);
    freeze(0);
    freeze(3);
    freeze(2);
    freeze(1);
    servox(3, 5, 2000);
    servox(2, 1600, 2000);
    fwd(50, 1000);
    freeze(0);
    freeze(3);
    freeze(2);
    freeze(1);
    servox(2, 100, 1500);
    //pvt(r, 20, 300);
    bwd(50, 1300);
    freeze(0);
    freeze(3);
    freeze(2);
    freeze(1);
    servox(2, 1600, 1500);
    fwd(50, 1300);
    freeze(0);
    freeze(3);
    freeze(2);
    freeze(1);
    servox(2, 100, 1500);





    /*for(int i=0; i<20; i++)
    {
        while (analog(0)>thresh0)
        {
            mecwsleep(50,10,10,50);
        }
        while (analog(0)<thresh0)
        {
            mecwsleep(10,50,50,10);
        }
    }
    STA(r,90);
    fwd(40,1000);
    loki();
    STA(l,180);
    sloki();
    fwd(75,1000);

    for(int i=0; i<17; i++)
    {
        while (analog(1)>thresh1)
        {
            mecwsleep(50,10,10,50);
        }
        while (analog(1)<thresh1)
        {
            mecwsleep(10,50,50,10);
        }
    }*/



    return 0;
}
void camera()
{
    camera_load_config("failure");
    camera_open();
    camera_update();
    int p = get_object_center_x(0,0);
    int b = get_object_center_x(1,0);
    int g = get_object_center_x(2,0);
    if(p<b && p<g)
    {
        printf("p on left\n");
        servo1 = 1169;
        servoice = 1169;
        // cup claw up down: 851
        // up/down drink 1817
        // open: 2046

    }
    else if(p>g && p>b)
    {
        printf("p on right\n");
        servo1 = 500;
        servoice = 530;
    }
    else
    {
        printf("p in middle\n");
        servo1 = 858;
        servoice = 858;
    }
    camera_close();
}