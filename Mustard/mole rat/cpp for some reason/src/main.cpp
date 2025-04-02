#include <kipr/wombat.h>
#include <iostream>
#include <test.h>

int main()
{
    mec mec;
    mpc mpc;
    turn turn;
    analogsensors a;
    servo servo;
    gyro gyro;
    thr thread;
    other other;
    shake shake;
    cam cam;




    mec.wait(2000);
    servo.servox(0,1410,1000);
    servo.servox(3,685,1000);
    servo.servox(1,2000,1000);
    servo.servox(2,100,1000);
    
    mec.wait(500);
    servo.servox(3,1540,500);
    
    cam.snap();
    
    a.localizeA();
    mec.wait(200);


    mec.fwd(100,1900);
    mec.wait(200);


    turn.spin(r,55,2500);
    turn.pvt(r,-25,800);
    turn.pvt(l,-25,900);

    ao();
    servo.servox(0,410,1500);

    mec.strafe(l,60,1750);

    mec.wait(700);






    turn.pvt(r,25,400);
    turn.pvt(l,-25,1300);
    //turn.pvt(r,25,1350);//pvt values for cups

    mec.strafe(l,20,3200);

    mec.bwd(25,400);

    turn.pvt(r,-25,100);
    turn.pvt(l,-25,1200);
    turn.pvt(r,25,700);//pvt values for cups

    mec.strafe(l,40,1800);

    mec.wait(700);

    turn.pvt(r,-25,900);

    ao();

    servo.servox(0,450,1000);

    //end cup grab
    mec.bwd(25,1400);

    a.loki();

    mec.strafe(r,45,2000);
    mec.bwd(75,700);
    turn.pvt(r,-25,500);
    turn.pvt(l,-25,600);

    while(analog(0)<thresh0)
    {
        mec.mecwsleep(-45,45,-45,45);//strafes until black line
    }
    while(analog(0)>thresh0)
    {
        break;
    }



    ao();
    servo.servox(0,1000,1000);
    mec.strafe(l,30,700);

    a.loki();
    gyro.calib_gyro_alpha();



    servo.servox(3,1500,1100);
    servo.servox(2,1900,1100);
    servo.servox(1,1850,1100);
    servo.servox(0,430,1500);
    for(int i=0; i<7; i++)
    {
        while (analog(1)>thresh1)
        {
            mec.mecwsleep(0,50,50,0);
        }
        while (analog(1)<thresh1)
        {
            mec.mecwsleep(50,0,0,50);
        }
    }

    while(analog(0)<thresh0)//goes until sees drink black line
    {
        mec.mecwsleep(50,45,45,50);
    }
    while(analog(0)>thresh0)
    {
        break;
    }

    mec.bwd(50,1700);

    ao();
    servo.servox(1,1750,700);
    servo.servox(3,40,2900);//downup
    mec.wait(500);
    turn.pvt(l,-35,210);

    ao();
    servo.servox(2,1900,1000);




    mec.fwd(25,2000);//first drink
    servo.servox(2,5,1100);//openclose
    turn.pvt(l,35,210);
    mec.bwd(25,3700);

    servo.servox(2,1850,1000);

    mec.fwd(45,1820); //second drink
    servo.servox(2,5,1100);//openclose
    turn.pvt(l,-35,410);
    mec.bwd(25,3700);



    servo.servox(3,1500,2500);


    ////////

    servo.servox(3,1960,1200);
    mec.wait(200);
    servo.servox(0,760,1200);
    servo.wait(200);
    servo.servox(1,1280,1500);
    mec.wait(200);
    servo.servox(2,1700,2700);
    mec.wait(200);

    servo.servox(0,410,1200);
    mec.wait(200);



    servo.servox(1,2000,1500);


    while(analog(0)<thresh0)
    {
        mec.ctrl(-50,-50,-50,-50);
    }
    while(analog(0)<thresh0)
    {
        break;
    }

    mec.strafe(r,70,1600);

    a.bloki();

    mec.strafe(r,70,1400);//strafes to blue pom wall

    mec.fwd(75,2000);//force localizes on blue pom wall
    mec.bwd(35,1000);
    
    servo.servox(2,1500,1000);
    servo.servox(3,50,2000);
    
    shake.pvtshakey(r,10);
    
    







    return 0;
}
