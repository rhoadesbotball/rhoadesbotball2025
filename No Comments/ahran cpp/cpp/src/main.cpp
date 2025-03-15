#include <kipr/wombat.h>
#include <iostream>
#include <alpha.h>
#include <cmath>

typedef struct Vector2{
    float x;
    float y;
} Vector2;
//gammapos[0] is pinkpos, [1] is bluepos, [2] is greenpos
int main()
{

    mec mec;
    turn turn;
    analogsensors a;
    servo servo;
    gyro gyro;
    
    
    cam cam;



    gyro.calib_gyro_alpha();




    servo.servox(3,145,2000);
    servo.servox(0,1550,2000);
    servo.servox(1,1811,2000);
    servo.servox(2,200,2000);

//needs to be fixed with new func
    int* alphapos[]={cam.snap()};
    int pink=*alphapos[0];
    int blue=*alphapos[1];
    int green=*alphapos[2];
    int gammapos[]={pink,blue,green};
//



    a.loki();





    servo.servox(3,1540,500);


    mec.wait(200);


    mec.fwd(100,1850);
    mec.wait(200);




    turn.spin(r,55,2500);
    turn.pvt(r,-25,800);
    turn.pvt(l,-25,900);

    ao();
    servo.servox(0,395,1500);

    mec.ctrl(50,-60,40,-60,1800);//perfect strafe

    mec.bwd(25,500);

    mec.strafe2(l,40,920);

    mec.wait(700);




	auto cupFunc=[=](){std::cout<<"lambda"<<std::endl;};

    turn.pvt(l,-25,600);
    turn.pvt(r,25,400);
    turn.pvt(l,-25,1600);
    turn.pvt(r,25,1050);//pvt values for cups

    mec.strafe2(l,60,2500);
    turn.pvt(r,-25,1100);
	mec.strafe2(l,60,900);
    mec.bwd(25,800);
    
    cupFunc();
   
    //end cup grab//
    mec.bwd(50,3000);




    a.loki();

    mec.strafe2(r,45,2000);
    servo.servox(0,470,1000);
    mec.bwd(75,700);
    turn.pvt(r,-25,500);
    turn.pvt(l,-25,600);

    while(analog(0)<thresh0)
    {
        mec.strafe2(r,50);//strafes until black line
    }
    while(analog(0)>thresh0)
    {
        break;
    }



    ao();
    servo.servox(0,1000,1000);
    mec.strafe2(l,30,700);

    a.loki();
    gyro.calib_gyro_alpha();



    servo.servox(3,1500,1100);
    servo.servox(2,1900,1100);
    servo.servox(1,1850,500);
    servo.servox(0,800,1500);
    for(int i=0; i<7; i++)
    {
        while (analog(1)>thresh1)
        {
            mec.mecwsleep(0,50,50,0);
        }
        while (analog(1)<thresh1)
        {
            mec.mecwsleep(100,0,0,100);
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

    gyro.align_gyro_alpha4();

    mec.bwd(50,1700);

    ao();
    servo.servox(1,1600,700);
    servo.servox(3,30,2900);//downup
    mec.wait(500);
    turn.pvt(l,-35,310);

    ao();
    servo.servox(2,1700,1000);




    mec.fwd(25,2300);//first drink
    servo.servox(2,75,1100);//openclose
    turn.pvt(l,35,210);
    mec.bwd(25,3700);

    servo.servox(2,1850,1000);

    mec.fwd(45,1950); //second drink
    servo.servox(2,75,1100);//openclose
    turn.pvt(l,-35,410);
    mec.bwd(25,2700);
    mec.diag(bl,50,1000);



    servo.servox(3,1500,2500);


    ////////
    printf("\n%d\n\n",gammapos[0]);


    servo.servox(3,1960,1200);
    mec.wait(200);
    servo.servox(1,gammapos[0],2500);
    mec.wait(200);
    servo.servox(0,790,1200);
    servo.wait(200);    
    servo.servox(2,2040,1900);
    mec.wait(200);

    servo.servox(0,490,1200);
    mec.wait(200);

    servo.servox(1,2000,1500);
    servo.servox(0,990,1200);
    //blue pom time
    
    mec.bwd(100,3000);
    
    a.loki();
    mec.fwd(50,4000);
    mec.bwd(50,500);
        
    turn.spin(l,55,2200);
    mec.fwd(100,1000);
    a.loki();
    mec.bwd(100,1200);
    
    mec.ctrl(-50,60,-40,60,500);//perfect strafe
    mec.ctrl(50,-60,40,-60,100);//perfect strafe
    
    servo.servox(0,550,1000);
    servo.servox(1,850,1000);
    servo.servox(2,1700,1000);
    servo.servox(3,5,2000);
    
    auto shakey=[=](int shake_multiplier){
        for(int j=0;j<shake_multiplier;j++){
        baasbennaguui(0,50);
        motor(3,50);
        msleep(100);
        }
    };
    shakey(10);
    
    servo.servox(2,100,1000);//grabs light blue poms    
    mec.wait(500);
    servo.servox(3,1960,2200);
    mec.wait(200);
    servo.servox(0,740,1200);
    servo.wait(200);
    servo.servox(1,gammapos[0],2500);
    mec.wait(200);
    servo.servox(2,2040,1900);
    mec.wait(200);
    
        
    


    return 69;
}