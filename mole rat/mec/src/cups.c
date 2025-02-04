#include <kipr/wombat.h>
#include <alpha.h>
#include <stdio.h>


int main()
{ 
    /*
    servox(1,1000,1200);
    servox(3,1000,6); 
    servox(2,1000,2000);


    servox(1,10000,544);

    */
    
    loki();
    fwd(100,2000);
    STA(r,90);
    loki();
    strafe(l,75,1000);
    
    
    return 0;
}