#include <kipr/wombat.h>
#include "strafe.h"

    
int main()
{
    servox(0,1000,400);
    servox(3,1000,1000);
    localizeA();
    PTA(l,90);
    locback();
    bwd(30,500);
    strafe(l,30,1000);
    localizeA();
     
        
    return 0;
}
