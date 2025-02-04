#include <kipr/wombat.h>

int r = 0;
int l = 1;
int fr=0;
int fl=1;
int bl=2;
int br=3;

int bias0=505;
int bias1=505;
int bias2=505;
int bias3=505;
double value=46.66666666667;

int svalue=27;//27-28

int thresh0=2700;
int thresh1=2700;

void mec(int u,int v, int w, int x, int sleep)
{
    motor(0,u);
    motor(3,x);
    motor(1,v);
    motor(2,w);
    msleep(sleep);
}

void fwd(int speed, int sleep)
{
    mec(speed,speed,speed,speed,sleep);  
}

void strafe(int direction, int speed, int duration)
{
    if (direction==r)
    {
        mec(-speed,speed-svalue,-(speed-svalue),speed-svalue,duration);
    }
    if (direction==l)
    {
        mec(speed,-(speed-svalue),speed-svalue,-(speed-svalue),duration);
    }

}

void diag(int direction,int speed,int sleep)
{

    if(direction == fl)
    {
        mec(speed,0,speed,0,sleep);
    }
    else if(direction == fr)
    {
        mec(0,speed,0,speed,sleep); 
    }

    else if(direction == br)
    {
        mec(-speed,0,-speed,0,sleep); 
    }

    else if(direction == bl)
    {
        mec(0,-speed,0,-speed,sleep); 
    }


}

void bwd(int speed, int sleep)
{
    mec(-speed,-speed,-speed,-speed,sleep);   
}
void pvt(int wheel, int speed, int sleep)
{
    if (wheel==r)
    {
        mec(speed,0,0,speed,sleep);
    }
    else if (wheel==l)
    {
        mec(0,speed,speed,0,sleep);
    }
}

void bpvt(int wheel, int speed, int sleep)
{
    if (wheel==r)
    {
        mec(-speed,0,0,-speed,sleep);
    }
    else if (wheel==l)
    {
        mec(0,-speed,-speed,0,sleep);
    }
}

void spin(int direction, int speed, int sleep)
{
    if (direction==l)
    {
        mec(speed,-speed,-speed,speed,sleep); 
    }
    else if (direction==r)
    {
        mec(-speed,speed,speed,-speed,sleep); 
    }
}

void veer(int direction, int speed, int veer, int sleep)
{
    if (direction==l)
    {
        mec(speed,speed-veer,speed-veer,speed,sleep); 
    }
    else if (direction==r)
    {
        mec(speed-veer,speed,speed,speed-veer,sleep); 
    }
}

void mecwsleep(int a, int b, int c, int d)
{
    motor(0,a);
    motor(1,b);
    motor(2,c);
    motor(3,d);  
}

void localizeA()
{
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(0,30,30,0);
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(30,0,0,30);
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(0,30,30,0);
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(30,0,0,30);
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
    while((analog(1)>3350) || (analog(0)>3350))
    {
        if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(0,30,30,0);
        }
        else if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(30,0,0,30);
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
}
void localizebA()
{
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(-30,0,0,-30); 
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(0,-30,-30,0);  
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(0,30,30,0);
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(30,0,0,30);  
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
    while((analog(1)>3350) || (analog(0)>3350))
    {
        if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(0,30,30,0); 
        }
        else if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(30,0,0,30); 
        }
        else
        {
            mecwsleep(30,30,30,30); 
        }
    }
}
void localizesA()
{
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(-30,30,30,-30); 
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(30,-30,-30,30);  
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(0,30,30,0);
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(30,0,0,30);  
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
    while((analog(1)>3350) || (analog(0)>3350))
    {
        if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(0,30,30,0); 
        }
        else if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(30,0,0,30); 
        }
        else
        {
            mecwsleep(30,30,30,30); 
        }
    }
}
void lokie()
{
    printf("this dosent work\n"); 

}

void loki()
{
    while(analog(1)<thresh1 || analog(0)<thresh0)
    {
        mecwsleep(50,50,50,50);
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            mecwsleep(0,50,50,0);
        }
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            mecwsleep(50,0,0,50);
        }
    }
    while(analog(1)>thresh1 || analog(0)>thresh0)
    {
        mecwsleep(50,50,50,50);
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            mecwsleep(0,50,50,0);
        }
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            mecwsleep(50,0,0,50);
        }
    }
}
void bloki()
{
    while(analog(1)<thresh1 || analog(0)<thresh0)
    {
        mecwsleep(50,50,50,50);
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            mecwsleep(-50,0,0,-50);
        }
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            mecwsleep(0,-50,-50,0);
        }
    }
    while(analog(1)>thresh1 || analog(0)>thresh0)
    {
        mecwsleep(50,50,50,50);
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            mecwsleep(-50,0,0,-50);
        }
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            mecwsleep(0,-50,-50,0);
        }
    }
}
void sloki()
{
    while(analog(1)<thresh1 || analog(0)<thresh0)
    {
        mecwsleep(50,50,50,50);
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            mecwsleep(-50,50,50,-50);
        }
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            mecwsleep(50,-50,-50,50);
        }
    }
    while(analog(1)>thresh1 || analog(0)>thresh0)
    {
        mecwsleep(50,50,50,50);
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            mecwsleep(-50,50,50,-50);
        }
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            mecwsleep(50,-50,-50,50);
        }
    }
}

void servox(int port, int time, int final)  
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
void PTA(int wheels, int theta)
{
    cmpc(0);
    cmpc(1);
    cmpc(2);
    cmpc(3);
    int bias0=270;
    int bias3=270;
    int bias1=270;
    int bias2=270;
    double value=46.6666666667;

    if(wheels==r)
    {
        while(gmpc(3)<((value*theta)-bias3) && gmpc(0)<((value*theta)-bias0))
        {
            motor(0,50);
            motor(3,50);
        }
    }
    else if(wheels==l)
    {
        while(gmpc(2)<((value*theta)-bias2) && gmpc(1)<((value*theta)-bias1))
        {
            motor(2,50);
            motor(1,50);
        }  
    }
    else
    {
    }

}
void STA(int direction, int theta)
{
    cmpc(0);
    cmpc(1);
    cmpc(2);
    cmpc(3);


    if(direction==l)
    {

        while(gmpc(3)<((value*theta)-bias3)/2 && gmpc(1)<((value*theta)-bias1)/2 && gmpc(0)<((value*theta)-bias0)/2 && gmpc(2)<((value*theta)-bias2)/2)
        {
            motor(0,50);
            motor(3,50);
            motor(2,-50);
            motor(1,-50);
        }
    }
    else if(direction==r)
    {

        while(gmpc(3)<((value*theta)-bias3)/2 && gmpc(1)<((value*theta)-bias1)/2 && gmpc(0)<((value*theta)-bias0)/2 && gmpc(2)<((value*theta)-bias2)/2)
        {
            motor(0,-50);
            motor(3,-50);
            motor(2,50);
            motor(1,50);
        }
    }
    else
    {
    }
}



