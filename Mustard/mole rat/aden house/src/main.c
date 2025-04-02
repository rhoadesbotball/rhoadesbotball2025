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
    
    
    wait(700);
    servox(0,1410,1000);
    servox(3,1510,1000);
    servox(1,2000,1000);
    servox(2,100,1000);
    
    loki();
    fwd(100,2000);
    STA(r,90);
    pvt(r,-25,1200);
    pvt(l,-25,900);
    
    ao();
    servox(0,380,1500);
    
    strafe(l,60,1350);
    
    wait(700);
    
    
    
    
    
    
    pvt(r,25,200);
    pvt(l,-25,1400);
    pvt(r,25,1350);//pvt values for cups
    
    strafe(l,45,1300);
    
    bwd(35,200);
    
    pvt(r,-25,100);
    pvt(l,-25,1100);
    pvt(r,25,900);//pvt values for cups
    
    strafe(l,45,1300);
    
    wait(700);
    
    ao();
    
    servox(0,470,1000);
    
    //end cup grab
    bwd(25,1400);
    
    loki();
    
    strafe(r,45,2000);
    bwd(75,700);
    pvt(r,-25,500);
    pvt(l,-25,600);
    
    while(analog(0)<thresh0)
    {
    mecwsleep(-45,45,-45,45);//strafes until black line
    }
    while(analog(0)>thresh0)
    {
    break;
    }
    
    ao();
    servox(0,1000,1000);
    strafe(l,30,700);
    
    loki();
    
    
    
    servox(3,1500,1000);
    servox(2,1900,1000);
    servox(1,1850,1000);
    servox(0,450,1200);
    for(int i=0; i<7; i++)
    {
        while (analog(1)>thresh1)
        {
            mecwsleep(0,50,50,0);
        }
        while (analog(1)<thresh1)
        {
            mecwsleep(50,0,0,50);
        }
    }
    
    while(analog(0)<thresh0)//goes until sees drink black line
    {
        mecwsleep(50,45,45,50);
    }
    while(analog(0)>thresh0)
    {
        break;
    }
    
    bwd(50,1700);
    
    ao();
    servox(3,5,2900);
    servox(1,1850,700);
    wait(500);
    pvt(l,-35,210);
    
    ao();
    servox(2,1900,1000);
    
    
    
    
    fwd(25,2000);
    servox(2,20,1100);
    pvt(l,35,210);
    bwd(25,3700);
    
    servox(2,1900,1000);
    
    fwd(45,1960);
    servox(2,20,1100);
    pvt(l,-35,310);
    bwd(25,3700);
    
    servox(3,1500,2500);
    
    
    ////////
    
    servox(3,1820,1200);
    wait(200);
    servox(0,750,1200);
    wait(200);
    servox(1,1140,1500);
    wait(200);
    servox(2,1700,2700);
    wait(200);
    
    
    return 69;
}