#include <kipr/wombat.h>
# include<loki2.h> 

int main()
{
    servox(0,10,450);
    sloki();
    forward(3500,75);
    backward(1500,75);
    
    freeze(0);
    freeze(1);
    freeze(2);
    freeze(3);
    servox(0,10,1000);
    
    
    bwd(100,1000);
    loki();
    pvt(l,75,400);
    bloki();
    
    
    
     
        
    return 0;
}
