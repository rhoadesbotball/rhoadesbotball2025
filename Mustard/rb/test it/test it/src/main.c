#include <kipr/wombat.h>

int main()
{
    while(digital(0)==0 || digital(9)==0)
    {
        motor(0,71);
        motor(3,70);
        while(digital(0)==1 && digital(9)==0)
        {
            motor(0,0);
            motor(3,60);
        }
        while(digital(0)==0 && digital(9)==1)
        {
            motor(0,60);
            motor(3,0);
        }
    }
    
    return 0;
}
