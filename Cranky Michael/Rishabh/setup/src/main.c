#include <kipr/wombat.h>

int main()
{
    cmpc(3);
    while(gmpc(3)<185-20)
    {
        motor(0,0);
        motor(3,20);
    }
    return 0;
}
