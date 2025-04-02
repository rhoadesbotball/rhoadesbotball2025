#include <kipr/wombat.h>
#include <iostream>
#include <alpha.h>
#include <cmath>



//x[0] is pinkpos, [1] is bluepos, [2] is greenpos
int main()
{
	//declaration of library defined class objects
    mec mec;
    turn turn;
    analogsensors a;
    servo servo;
    gyro gyro;
    
    
    cam cam;

    

    


// servo setup for start position
    servo.servox(3,145,700);
    servo.servox(0,1550,700);
    servo.servox(1,1911,800);
    servo.servox(2,200,500);
    
    


    int x[3];
    cam.snap4(x);// snaps picture w color cam and store positions of cups in x[]
    



    shut_down_in(119);
//program start
    a.loki();// localize





    servo.servox(3,1540,500);


    mec.wait(200);


    mec.fwd(100,1850);
    mec.wait(200);


// soft force licalize w wall to prevent accidental strafing

    turn.spin(r,55,2500);
    turn.pvt(r,-25,800);
    turn.pvt(l,-25,900);

    ao();
    servo.servox(0,395,1500);// cup effector servo down

//aligns effector to grab cups
    mec.ctrl(50,-60,40,-60,1800);//perfect strafe to align cups in effector

    mec.bwd(25,500);

    mec.strafe2(l,40,920);

    mec.wait(700);



//pivots to get a good angle to push cups into effector
	

    turn.pvt(l,-25,600);
    turn.pvt(r,25,400);
    turn.pvt(l,-25,1600);
    turn.pvt(r,25,1050);//pvt values for cups

    mec.strafe2(l,60,2500);
    turn.pvt(r,-25,1000);
	mec.strafe2(l,60,900);
    mec.bwd(25,800);
    
    
   
    //end cup grab//
    mec.bwd(50,3000);//force localize w wall


// starts journey to pink drinks

    a.loki();

    mec.strafe2(r,45,2000);
    servo.servox(0,470,1000);
    mec.bwd(75,700);
    turn.pvt(r,-25,500);
    turn.pvt(l,-25,600);

    while(analog(0)<thresh0)
    {
        mec.strafe2(r,50);//strafes until black line of start box
    }
    while(analog(0)>thresh0)
    {
        break;
    }



    ao();
    servo.servox(0,1000,1000);
    mec.strafe2(l,30,700);

    a.loki();
    gyro.calib_gyro_alpha();// calibrates script gyroscope (needs patch)
    

//positiions servos to get ready to grab drinks
    servo.servox(3,1500,1100);
    servo.servox(2,1900,1100);
    servo.servox(1,1850,1500);
    servo.servox(0,800,1500);
    
//line follows with line to the side of pink drinks
    for(int i=0; i<3; i++)
    {
        while (analog(1)>thresh1)
        {
            mec.mecwsleep(0,50,50,0);
        }
        while (analog(1)<thresh1)
        {
            mec.mecwsleep(90,0,0,90);
        }
    }

    while(analog(0)<thresh0)//goes until sees pink drink side line(moves forward but cups restrict movement on left wheels resulting in a pivo until analog(0) sees side line)
    {
        mec.mecwsleep(50,45,45,50);
    }
    while(analog(0)>thresh0)
    {
        break;
    }

    
// align to grab drinks
    mec.bwd(50,1700);
	
    ao();
    servo.servox(1,1600,700);
    servo.servox(3,30,2900);
    mec.wait(500);
    turn.pvt(l,-35,110);

    ao();
    servo.servox(2,2000,1000);
//end alignment//



    mec.fwd(25,2300);//first drink
    servo.servox(2,50,1100);//openclose
    turn.pvt(l,35,210);
    mec.bwd(25,3700);

    servo.servox(2,1850,1000);

    mec.fwd(45,2180); //second drink
    servo.servox(2,50,1100);//openclose
    turn.pvt(l,-35,410);
    mec.bwd(30,1850);
    turn.pvt(r,-35,270);
    mec.diag(bl,50,1200);



    servo.servox(3,1500,2500);


    ////////
    printf("\n\t%d\n\n",x[0]);// prints pink cup position(stored in x[] at index [0])

    //aligns effector with pink cup and drops
    servo.servox(0,490,700);
    servo.servox(3,1960,1200);
    mec.wait(200);
    servo.servox(1,x[0],2800);
    mec.wait(200);
    servo.servox(0,790,1200);
    servo.wait(200);    
    servo.servox(2,2040,1900);
    mec.wait(200);

    servo.servox(0,490,1200);
    mec.wait(200);

    servo.servox(1,2000,1500);
    servo.servox(0,990,1200);
    mec.wait(6500);
//end drink drop into pink cup// 
    
    
    
    mec.bwd(100,3000);
    
    a.loki();
    mec.bwd(100,1000);
    
        
    turn.spin(l,55,2500);
    
    mec.bwd(100,10000);
    a.loki();
    
    
    
    
    return 69;
}