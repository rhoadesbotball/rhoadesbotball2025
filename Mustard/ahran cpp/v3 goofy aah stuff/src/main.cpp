const int r2=468;
const int m=888;
const int l2=1204;
#include <kipr/wombat.h>
#include <iostream>
#include <alpha.h>
#include <cmath>
#include <thread>
#include <chrono>
#include <stdbool.h>
using namespace std::literals::chrono_literals;



int main()
{
    enable_servos();
    //declaration of library defined class objects
    mec mec;
    turn turn;
    analogsensors a;
    servo servo;
    gyro gyro;


    cam cam;






    // servo setup for start position(in threads for faster use)

    std::thread servo0(&servo::servox,&servo,0,1555,10);
    std::thread servo1(&servo::servox,&servo,1,1900,10);
    std::thread servo2(&servo::servox,&servo,2,133,10);
    std::thread servo3(&servo::servox,&servo,3,145,10);

    servo0.join();
    servo2.join();
    servo1.join();
    servo3.join();


    //mec.wait(2000);


    int x;
    char pinkposchar=cam.snap6(x);// snaps picture w color cam and store position of pink cup in x
    std::cout<<pinkposchar<<std::endl;



    shut_down_in(119);

    //program start

    std::thread localize(&analogsensors::loki,&a);
    std::thread servomoveup(&servo::servox,&servo,3,1220,900);



    localize.join();
    servomoveup.join();


    mec.fwd(100,1850);





    turn.spin(r,55,2500);

    // soft force licalize w wall to prevent accidental strafing/cup effector servo down
    std::thread cupservo(&servo::servox,&servo,0,375,500);
    std::thread smallLokiPt1(&turn::pvt,&turn,r,-25,800);

    cupservo.join();
    smallLokiPt1.join();


    turn.pvt(l,-27,1500);

    ao();


    //aligns effector to grab cups
    mec.ctrl(50,-60,40,-60,1900);//perfect strafe to align cups in effector

    mec.bwd(25,500);

    mec.strafe2(l,40,620);





    //pivots to get a good angle to push cups into effector


    turn.pvt(l,-70,250);
    turn.pvt(r,50,200);
    turn.pvt(l,-25,1000);
    turn.pvt(r,70,375);//pvt values for cups

    mec.strafe2(l,87,900);
    turn.pvt(r,-30,400);
    mec.strafe2(l,70,400);
    //mec.bwd(35,800);
    //turn.pvt(l,-35,1000);



    //end cup grab//

    //mec.bwd(64,1000);//force localize w wall
    servo.servox(0,750,800);//servo updown
    servo.servox(0,380,1000);


    // starts journey to pink drinks

    //a.loki();


    mec.strafe2(r,45,1000);
    //servo.servox(0,420,700);
    mec.bwd(75,1200);
    turn.pvt(r,-25,500);
    turn.pvt(l,-25,600);

    while(analog(0)<thresh0)
    {
        mec.strafe2(r,70);//strafes until black line of start box
    }
    while(analog(0)>thresh0)
    {
        break;
    }



    ao();
    servo.servox(0,1000,1700);
    mec.strafe2(l,30,1700);

    a.loki();
    //gyro.calib_gyro_alpha();// calibrates script gyroscope (needs patch)


    std::cout<<"bruh"<<std::endl;
    
    //positiions servos to get ready to grab drinks
    servo.servox(3,1500,500);
    servo.servox(2,1900,500);
    servo.servox(1,1850,500);
    servo.servox(0,400,1100);

    //line follows with line to the side of pink drinks
    for(int i=0;i<3;i++){
        while (analog(1)>thresh1)
        {
            mec.mecwsleep(0,100,100,0);
        }
        while (analog(1)<thresh1)
        {
            mec.mecwsleep(90,0,0,90);
        }
    }
    turn.pvt(l,35,900);
    while (analog(0)<thresh0)
    {
        mec.mecwsleep(90,90,90,90);
    }
    while (analog(0)>thresh0){break;}



    //a.loki();
    //mec.wait(3000);

    // align to grab drinks
    mec.bwd(55,2200);

    ao();
    servo.servox(1,1890,700);//servo 1 val
    servo.servox(3,60,1900);
    mec.wait(5000);//wait thingy
    turn.pvt(l,-35,110);

    ao();
    servo.servox(2,2000,1000);
    //end alignment//



    mec.fwd(25,2300);//first drink
    servo.servox(2,50,1100);//openclose
    //turn.pvt(l,35,210);
    mec.bwd(50,1850);

    servo.servox(2,1850,900);

    mec.fwd(51,1890); //second drink
    servo.servox(2,50,1100);//openclose
    //turn.pvt(l,-35,410);
    mec.bwd(52,1500);






    ////////
    printf("\n\t%d\n",x);// prints pink cup position(stored in x)

    //aligns effector with pink cup and drops

    std::thread servo00(&servo::servox,&servo,0,490,1500);
    std::thread servo03(&servo::servox,&servo,3,2030,2500);


    servo03.join();
    servo00.join();

    if(pinkposchar=='l'){
        mec.wait(200);
        servo.servox(1,x,3700);
        //mec.fwd(51,2000);
        servo.servox(0,850,1500);
        servo.wait(200);    
        servo.servox(2,2040,900);
        mec.wait(200);

        servo.servox(0,490,1500);   
    }
    if(pinkposchar=='r'){
        mec.wait(200);
        servo.servox(1,x,3700);
        mec.wait(200);
        servo.servox(0,850,1500);
        servo.wait(200);    
        servo.servox(2,2040,900);
        mec.wait(200);

        servo.servox(0,490,2300);   
    }
    if(pinkposchar=='m'){
        servo.servox(3,1980,500);
        mec.wait(200);
        servo.servox(1,x,3700);
        mec.wait(200);
        servo.servox(0,762,1500);
        servo.wait(200);    
        servo.servox(2,2040,900);
        mec.wait(200);

        servo.servox(0,490,1500);   
    }
    std::cout<<"yo"<<std::endl;



    //end drink drop into pink cup// 

    //reset servo pos//


    while(analog(0)<thresh0)//goes until sees pink drink line again
    {
        mec.mecwsleep(70,65,65,70);
    }
    while(analog(0)>thresh0)
    {
        break;
    }
    mec.bwd(74,2000);
    servo.servox(1,1891,700);
    servo.servox(3,30,900);
    servo.servox(2,2040,700);
    //2//

    mec.fwd(45,2350);//another drink
    servo.servox(2,50,1100);//openclose
    //turn.pvt(l,35,210);
    //mec.wait(450);//waits for other robot to pass
    mec.bwd(50,2350);






    //aligns effector with pink cup again cup and drops
    std::thread servo_0(&servo::servox,&servo,0,490,1500);
    std::thread servo_3(&servo::servox,&servo,3,2030,2500);


    servo_3.join();
    servo_0.join();

    if(pinkposchar=='l'){
        mec.wait(200);
        servo.servox(1,x,3700);
        //mec.fwd(51,2000);
        servo.servox(0,850,1500);
        servo.wait(200);    
        servo.servox(2,2040,900);
        mec.wait(200);

        servo.servox(0,490,1500);   
    }
    if(pinkposchar=='r'){
        mec.wait(200);
        servo.servox(1,x,3700);
        mec.wait(200);
        servo.servox(0,850,1500);
        servo.wait(200);    
        servo.servox(2,2040,900);
        mec.wait(200);

        servo.servox(0,490,2300);   
    }
    if(pinkposchar=='m'){
        servo.servox(3,1980,500);
        mec.wait(200);
        servo.servox(1,x,3700);
        mec.wait(200);
        servo.servox(0,762,1500);
        servo.wait(200);    
        servo.servox(2,2040,900);
        mec.wait(200);

        servo.servox(0,490,1500);   
    }


    //reset servos again//for last two cups
    servo.servox(0,400,1500);   
    servo.servox(1,1891,700);
    servo.servox(3,1230,900);
    servo.servox(2,2040,700);

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
	turn.pvt(l,50,700);

    while(analog(0)<thresh0)//goes until sees pink drink side line(moves forward but cups restrict movement on left wheels resulting in a pivo until analog(0) sees side line)
    {
        mec.mecwsleep(70,65,65,70);
    }
    while(analog(0)>thresh0)
    {
        break;
    }

    mec.bwd(55,2200);

    servo.servox(3,50,1900);





    mec.fwd(25,2300);//first drink again
    servo.servox(2,50,1100);//openclose
    //turn.pvt(l,35,210);
    mec.bwd(50,1850);

    servo.servox(2,1850,900);

    mec.fwd(51,2090); //second drink again
    servo.servox(2,50,1100);//openclose
    //turn.pvt(l,-35,410);
    mec.bwd(52,1500);


    servo.servox(0,490,900);
    turn.pvt(r,-85,1000);//pvt thingy

    //mec.fwd(70,900);

    mec.bwd(-100,1000);

    a.loki();

    mec.fwd(50,1000);
    turn.spin(l,55,2500);
    a.loki();

    //aligns effector with pink cup again cup and drops
    std::thread servo0000(&servo::servox,&servo,0,490,1500);
    std::thread servo0003(&servo::servox,&servo,3,2030,2500);

    servo0003.join();
    servo0000.join();

    if(pinkposchar=='l'){
        mec.wait(200);
        servo.servox(1,r2,3700);
        //mec.fwd(51,2000);
        servo.servox(0,850,1500);
        servo.wait(200);    
        servo.servox(2,2040,900);
        mec.wait(200);

        servo.servox(0,490,1500);   
    }
    if(pinkposchar=='r'){
        mec.wait(200);
        servo.servox(1,l2,3700);
        mec.wait(200);
        servo.servox(0,850,1500);
        servo.wait(200);    
        servo.servox(2,2040,900);
        mec.wait(200);

        servo.servox(0,490,2300);   
    }
    if(pinkposchar=='m'){
        servo.servox(3,1980,500);
        mec.wait(200);
        servo.servox(1,l2,3700);
        mec.wait(200);
        servo.servox(0,762,1500);
        servo.wait(200);    
        servo.servox(2,2040,900);
        mec.wait(200);

        servo.servox(0,490,1500);   
    }



    mec.bwd(100,900);
    turn.spin(l,55,2500);
    //a.loki();
    mec.bwd(35,700);
    while(analog(1)<thresh1){
        mec.strafe2(l,70);
    }
    mec.strafe(r,55,1000);
    a.loki();
    mec.bwd(50,1000);
    mec.strafe(r,75,900);
    
    //int x=r2;
    //char pinkposchar='r';
    constexpr int serval=60;
    //mec.strafe(r,50,1000);

    servo.servox(0,420,1500);
    servo.servox(3,1200,1900);
    mec.wait(200);
    servo.servox(1,895,500);
    //mec.wait(200);
    servo.servox(2,1745,900);
    //mec.wait(200);
    servo.servox(3,serval,1070);//servo 3 when shakes
    mec.wait(200);


    auto shake=[=](int times,int sleep)->void{

        for(int i=0;i<times;i++){

            motor(0,75);
            motor(3,75);
            motor(1,75);
            motor(2,75);
            msleep(sleep);

            motor(3,-75);
            motor(0,-75);
            motor(1,-75);
            motor(2,-75);
            msleep(sleep);
        }

    };



    shake(7,140);
    mec.ctrl(50,-50,0,0,200);
    mec.wait(100);
    servo.servox(3,10,900);
    mec.wait(200);
    servo.servox(2,45,400);
    mec.wait(300);
    servo.servox(3,1240,900);


    //std::thread servo3_(&servo::servox,&servo,3,2030,2500);

	servo.servox(3,2030,2500);

    //servo3_.join();

    //pom drops into cups
    if(pinkposchar=='l'){
        mec.wait(200);
        servo.servox(1,x,3700);
        //mec.fwd(51,2000);
        servo.servox(0,790,1500);
        servo.wait(200);    
        servo.servox(2,2040,1300);
        mec.wait(200);

        servo.servox(0,490,1500);   
    }
    if(pinkposchar=='r'){
        mec.wait(200);
        servo.servox(1,x,3700);
        mec.wait(200);
        servo.servox(0,850,1500);
        servo.wait(200);    
        servo.servox(2,2040,1300);
        mec.wait(200);

        servo.servox(0,490,2300);   
    }
    if(pinkposchar=='m'){
        servo.servox(3,2040,500);
        mec.wait(200);
        servo.servox(1,x,3700);
        mec.wait(200);
        servo.servox(0,736,1500);
        servo.wait(200);    
        servo.servox(2,2040,1300);
        mec.wait(200);

        servo.servox(0,490,1500);   
    }




	servo.servox(1,945,900);
    servo.servox(2,1745,900);
	servo.servox(3,1240,900);

    mec.fwd(25,500);
    servo.servox(1,745,900);//servo move val
    mec.wait(200);
    servo.servox(2,1745,900);
    mec.wait(200);
    servo.servox(3,serval,1900);//servo 3 when shakes
    mec.wait(200);

    shake(7,150);
    mec.wait(100);
    servo.servox(3,10,900);
    mec.wait(200);
    servo.servox(2,45,900);
    mec.wait(100);
    servo.servox(3,1240,900);

    //std::thread servo0000(&servo::servox,&servo,0,490,1500);
    servo.servox(3,2030,1500);

    //pom drops into cups
    if(pinkposchar=='l'){
        mec.wait(200);
        servo.servox(1,x,3700);
        //mec.fwd(51,2000);
        servo.servox(0,790,1500);
        servo.wait(200);    
        servo.servox(2,2040,900);
        mec.wait(200);

        servo.servox(0,490,1500);   
    }
    if(pinkposchar=='r'){
        mec.wait(200);
        servo.servox(1,x,3700);
        mec.wait(200);
        servo.servox(0,850,1500);
        servo.wait(200);    
        servo.servox(2,2040,900);
        mec.wait(200);

        servo.servox(0,490,2300);   
    }
    if(pinkposchar=='m'){
        servo.servox(3,2040,500);
        mec.wait(200);
        servo.servox(1,x,3700);
        mec.wait(200);
        servo.servox(0,732,1500);
        servo.wait(200);    
        servo.servox(2,2040,900);
        mec.wait(200);

        servo.servox(0,490,1500);   
    }





    return 0;
}