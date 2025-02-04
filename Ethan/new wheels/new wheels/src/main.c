#include <kipr/wombat.h>
#include <loki.h>
#include <stdio.h>


int main()
{
    servox(0,1000,250);
    localizebA();
    fwd(75,2500);
    servox(0,1000,500);
    bwd(75,1000);
    servox(0,1000,1000);
    bwd(50,2000);
    servox(0,1000,200);
    msleep(500);
    bwd(50,500);
    localizebA();
    servox(0,1000,800);
    spin(r,60,3000);
    localizebA();
    servox(0,1000,800);
    fwd(75,500);
    return 0;
}