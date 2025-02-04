#include <kipr/wombat.h>

int r = 0;
int l = 1;
int fr=0;
int fl=1;
int bl=2;
int br=3;


void mec(int u,int v, int w, int x, int y)
{
    motor(0,u);
    motor(3,x);
    motor(1,v);
    motor(2,w);
    msleep(y);
}

void fwd(int x, int y)
{
    mec(x,x,x,x,y);  
}

void strafe(int speed, int duration)
{
    mec(-speed,speed,-speed,speed,duration);
}

void diag(int w,int x,int y)
{

    if(w == fl)
    {
        mec(x,0,x,0,y);
    }
    else if(w == fr)
    {
        mec(0,x,0,x,y); 
    }

    else if(w == br)
    {
        mec(-x,0,-x,0,y); 
    }

    else if(w == bl)
    {
        mec(0,-x,0,-x,y); 
    }


}

void bwd(int x, int y)
{
    mec(-x,-x,-x,-x,y);   
}
void pvt(int w, int s, int m)
{
    if (w==r)
    {
        mec(s,0,0,s,m);
    }
    else if (w==l)
    {
        mec(0,s,s,0,m);
    }
}

void bpvt(int w, int s, int m)
{
    if (w==r)
    {
        mec(-s,0,0,-s,m);
    }
    else if (w==l)
    {
        mec(0,-s,-s,0,m);
    }
}

void spin(int w, int x, int y)
{
    if (w==l)
    {
        mec(x,-x,-x,x,y); 
    }
    else if (w==r)
    {
        mec(-x,x,x,-x,y); 
    }
}

void veer(int w, int x, int vs, int y)
{
    if (w==l)
    {
        mec(x,x-vs,x-vs,x,y); 
    }
    else if (w==r)
    {
        mec(x-vs,x,x,x-vs,y); 
    }
}
void strafee(int speed, int duration)
{
    mec(-speed,speed,-speed,speed,duration);
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
void linefollow(double time)
{	
    double timestart = seconds();
    while(seconds() - timestart < time)
    {
        while(analog(0)>3350)
        {
            mecwsleep(100,-100,-100,100);
        }
        while(analog(0)<3350)
        {
            mecwsleep(0,100,100,0);
        }
    }
}