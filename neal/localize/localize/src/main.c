#include<kipr/wombat.h>
int main()

{

    while(analog(1)<3700 || analog(0)<3700)
    {
        while(analog(1)<3700 && analog(0)>3700)
        {
            motor(0,1);
            motor(3,30);
        }
        while(analog(1)>3700 && analog(0)<3700)
        {
            motor(3,0);
            motor(0,31);
        }
        
    }
    while(analog(1)>3700 || analog(0)>3700)
    {
        while(analog(1)>3700 && analog(0)<3700)
        {
            motor(0,1);
            motor(3,30);
        }
        while(analog(1)<3700 && analog(0)>3700)
        {
            motor(3,0);
            motor(0,31);
        }
        motor(3,75);
        motor(0,76);
    }
    
    return 0;
}