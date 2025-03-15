#include <kipr/wombat.h>
#include <alpha.h>
//after strafe gyro needs recalibration
int main()
{
    
    

    
    wait(700);
    servox(0,1410,1000);
    servox(3,1510,1000);
    servox(1,2000,1000);
    servox(2,100,1000);
    
    loki();
    wait(200);
    calib_gyro_alpha();
    
    fwd(100,2050);
    wait(200);
    align_gyro_alpha2(0);
    STA(r,90);
    pvt(r,-25,800);
    pvt(l,-25,900);
    
    ao();
    servox(0,410,1500);
    
    strafe(l,60,1450);
    
    wait(700);
    
    
    
    fwd(20,300);
    
    
    pvt(r,25,500);
    pvt(l,-25,1400);
    pvt(r,25,1350);//pvt values for cups
    
    strafe(l,40,1500);
    
    bwd(25,400);
    
    pvt(r,-25,100);
    pvt(l,-25,1200);
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
    calib_gyro_alpha();
    
    
    
    servox(3,1500,1100);
    servox(2,1900,1100);
    servox(1,1850,1100);
    servox(0,455,1500);
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
    servox(3,40,2900);//downup
    servox(1,1750,700);
    wait(500);
    pvt(l,-35,210);
    
    ao();
    servox(2,1900,1000);
    
    
    
    
    fwd(25,2000);//first drink
    servox(2,5,1100);//openclose
    pvt(l,35,210);
    bwd(25,3700);
    
    servox(2,1850,1000);
    
    fwd(45,1820); //second drink
    servox(2,5,1100);//openclose
    pvt(l,-35,410);
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
    
    servox(0,410,1200);
    wait(200);
    
    
    
    servox(1,2000,1500);
    
    
    bwd(100,2000);
    
    loki();
    servox(0,100,1000);
    
    strafe(r,50,1200);
    
    
    
    gyroalpha_fwd(75,10);
    
    
    
    
    
    
    return 69;
}
