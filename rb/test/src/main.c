#include <kipr/wombat.h>

int main()
{
    int thresh0 = 3100;
    int thresh1 = 3100;
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

    return 0;
}
