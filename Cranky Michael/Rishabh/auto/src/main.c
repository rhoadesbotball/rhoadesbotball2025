#include <kipr/wombat.h>

int main()
{
    cmpc(3);
    while(gmpc(3)<205-26)
    {
        motor(3,20);
        motor(0,0);
    }
    return 0;
}
