#include <kipr/wombat.h>
int thresh0 = 3500;
int thresh1 = 3500;
int main()
{
    while(analog(0)<thresh0 || analog(1)<thresh1)// square up
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
    }
    return 0;
}
