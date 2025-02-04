#include <kipr/wombat.h>
void localizeA();
void localizeD();
int main()
{
   
    
	localizeA();
    return 0;
}
void localizeD()
{
    while((digital(1)==0) || (digital(0)==0))
    {
        if ((digital(1)==1) && (digital(0)==0))
        {
            motor(0,-30);
            motor(1,30);
            motor(2,30);
            motor(3,-30);
        }
        else if ((digital(1)==0) && (digital(0)==1))
        {
            motor(0,30);
            motor(1,-30);
            motor(2,-30);
            motor(3,30);
        }
        else if ((digital(1)==0) && (digital(0)==0))
        {
            motor(0,30);
            motor(1,30);
            motor(2,30);
            motor(3,30);
        }

        else 
        {
            motor(3,0);
            motor(0,0);
        }
    }
}
void localizeA()
{
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            motor(0,0);
            motor(3,30);
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            motor(3,0);
            motor(0,30);
        }
        else
        {
            motor(3,30);
            motor(0,30);
        }
    }while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            motor(0,0);
            motor(3,30);
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            motor(3,0);
            motor(0,30);
        }
        else
        {
            motor(3,30);
            motor(0,30);
        }
    }
    while((analog(1)>3350) || (analog(0)>3350))
    {
        if ((analog(1)>3350) && (analog(0)<3350))
        {
            motor(0,0);
            motor(3,30);
        }
        else if ((analog(1)<3350) && (analog(0)>3350))
        {
            motor(3,0);
            motor(0,30);
        }
        else
        {
            motor(3,30);
            motor(0,30);
        }
    }
}