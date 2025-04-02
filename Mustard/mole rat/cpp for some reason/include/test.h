int r=1;
int l=0;
int fr=0;
int fl=1;
int bl=2;
int br=3;

int f=0;
int b=1;

int bias0=505;
int bias1=505;
int bias2=505;
int bias3=505;
double value=46.66666666667;

int svalue=0;

int thresh0=3150;
int thresh1=3150;

double bias12=70;
double bias03=45;

int gmpc0=gmpc(0)-bias03;
int gmpc1=gmpc(1)-bias12;
int gmpc2=gmpc(2)-bias12;
int gmpc3=gmpc(3)-bias03;

short analog0w;
short analog1w;
short analog0b;
short analog1b;


class mec
{
    public:

    void fwd(int speed, int time)
    {
        motor(0,speed);
        motor(1,speed);
        motor(2,speed);
        motor(3,speed);
        msleep(time);
    }
    void bwd(int speed, int time)
    {
        motor(0,-speed);
        motor(1,-speed);
        motor(2,-speed);
        motor(3,-speed);
        msleep(time);
    }
    void control(int speed0,int speed1,int speed2,int speed3,int time)
    {
        motor(0,speed0);
        motor(1,speed1);
        motor(2,speed2);
        motor(3,speed3);
        msleep(time);  
    }
    void control(int speed0,int speed1,int speed2,int speed3)
    {
        motor(0,speed0);
        motor(1,speed1);
        motor(2,speed2);
        motor(3,speed3);

    }
    void ctrl(int speed0,int speed1,int speed2,int speed3)
    {
        motor(0,speed0);
        motor(1,speed1);
        motor(2,speed2);
        motor(3,speed3);

    }
    void ctrl(int speed0,int speed1,int speed2,int speed3,int time)
    {
        motor(0,speed0);
        motor(1,speed1);
        motor(2,speed2);
        motor(3,speed3);
        msleep(time);  
    }
    void mecwsleep(int speed0,int speed1,int speed2,int speed3)
    {
        motor(0,speed0);
        motor(1,speed1);
        motor(2,speed2);
        motor(3,speed3);
    }
    void wait(int time)
    {
    ctrl(0,0,0,0,time);
    }


void diag(int direction, int speed, int sleep)
{
if(direction == fl)
    {
        control(speed,0,speed,0,sleep);
    }
    else if(direction == fr)
    {
        control(0,speed,0,speed,sleep); 
    }

    else if(direction == br)
    {
        control(-speed,0,-speed,0,sleep); 
    }

    else if(direction == bl)
    {
        control(0,-speed,0,-speed,sleep); 
    }
}
void strafe(int direction, int speed, int duration)
{
    if (direction==r)
    {
        control(-speed,speed,-speed,speed,duration);
    }
    if (direction==l)
    {
        control(speed,-speed,speed,-speed,duration);
    }

}
void bwdwheelstrafe(int speed,long int time)
{
ctrl(0,0,speed,-speed,time);
}
};
class shake : public mec
{
public:
void pvtshakey(int wheel,int times)
{
   if (wheel==r)
   {
       for(int i=0;i<times;i++)
       {
       ctrl(50,0,0,50,100);
       ctrl(-50,0,0,-50,100);
       }
   }
    if (wheel==r)
   {
       for(int i=0;i<times;i++)
       {
       ctrl(0,50,50,0,100);
       ctrl(0,-50,-50,0,100);
       }
   }
}
};

class mpc
{

public:


void fwd(int speed, int ticks)
{
while(gmpc(0)<ticks + gmpc0 || gmpc(3)<ticks + gmpc3 || gmpc(1)<ticks + gmpc1 || gmpc(2)<ticks + gmpc2)
{
motor(0,speed);
motor(3,speed);
motor(1,speed);
motor(2,speed);
}

}
void STA(int direction, int theta)
{



    if(direction==r)
    {

        while(gmpc(3)<((value*theta)-bias3)/2 + gmpc3 && gmpc(1)<((value*theta)-bias1)/2 + gmpc1 && gmpc(0)<((value*theta)-bias0)/2 + gmpc0 && gmpc(2)<((value*theta)-bias2)/2 + gmpc2)
        {
            motor(0,-50);
            motor(3,-50);
            motor(2,50);
            motor(1,50);
        }
    }
    else if(direction==l)
    {

        while(gmpc(3)<((value*theta)-bias3)/2 + gmpc3 && gmpc(1)<((value*theta)-bias1)/2 + gmpc1 && gmpc(0)<((value*theta)-bias0)/2 + gmpc0 && gmpc(2)<((value*theta)-bias2)/2 + gmpc2)
        {
            motor(0,50);
            motor(3,50);
            motor(2,-50);
            motor(1,-50);
        }
    }
    else
    {
    }
}

};
class turn : public mec
{
public:
void pvt(int wheel, int speed, int sleep)
{
    if (wheel==r)
    {
        ctrl(speed,0,0,speed,sleep);
    }
    else if (wheel==l)
    {
        ctrl(0,speed,speed,0,sleep);
    }
}



void spin(int direction, int speed, int sleep)
{
    if (direction==l)
    {
        ctrl(speed,-speed,-speed,speed,sleep); 
    }
    else if (direction==r)
    {
        ctrl(-speed,speed,speed,-speed,sleep); 
    }
}

void veer(int direction, int speed, int veer, int sleep)
{
    if (direction==l)
    {
        ctrl(speed,speed-veer,speed-veer,speed,sleep); 
    }
    else if (direction==r)
    {
        ctrl(speed-veer,speed,speed,speed-veer,sleep); 
    }
}



};
class analogsensors : public mec
{
public:

void localizeA()
{
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(0,30,30,0);
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(30,0,0,30);
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(0,30,30,0);
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(30,0,0,30);
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
    while((analog(1)>3350) || (analog(0)>3350))
    {
        if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(0,30,30,0);
        }
        else if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(30,0,0,30);
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
}
void localizebA()
{
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(-30,0,0,-30); 
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(0,-30,-30,0);  
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(0,30,30,0);
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(30,0,0,30);  
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
    while((analog(1)>3350) || (analog(0)>3350))
    {
        if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(0,30,30,0); 
        }
        else if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(30,0,0,30); 
        }
        else
        {
            mecwsleep(30,30,30,30); 
        }
    }
}
void localizesA()
{
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(-30,30,30,-30); 
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(30,-30,-30,30);  
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(0,30,30,0);
        }
        else if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(30,0,0,30);  
        }
        else
        {
            mecwsleep(30,30,30,30);
        }
    }
    while((analog(1)>3350) || (analog(0)>3350))
    {
        if ((analog(1)>3350) && (analog(0)<3350))
        {
            mecwsleep(0,30,30,0); 
        }
        else if ((analog(1)<3350) && (analog(0)>3350))
        {
            mecwsleep(30,0,0,30); 
        }
        else
        {
            ctrl(30,30,30,30); 
        }
    }
}
void lokie(char a)
{
    std::cout<<"this dosent work\n"<<a; 

}

void loki()
{
    while(analog(1)<thresh1 || analog(0)<thresh0)
    {
        mecwsleep(50,50,50,50);
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            ctrl(0,50,50,0);
        }
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            ctrl(50,0,0,50);
        }
    }
    while(analog(1)>thresh1 || analog(0)>thresh0)
    {
            ctrl(50,50,50,50);
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            ctrl(0,50,50,0);
        }
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            ctrl(50,0,0,50);
        }
    }
}
void bloki()
{
    while(analog(1)<thresh1 || analog(0)<thresh0)
    {
        mecwsleep(50,50,50,50);
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            ctrl(-50,0,0,-50);
        }
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            ctrl(0,-50,-50,0);
        }
    }
    while(analog(1)>thresh1 || analog(0)>thresh0)
    {
        mecwsleep(50,50,50,50);
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            ctrl(-50,0,0,-50);
        }
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            ctrl(0,-50,-50,0);
        }
    }
}
void sloki()
{
    while(analog(1)<thresh1 || analog(0)<thresh0)
    {
        mecwsleep(50,50,50,50);
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            ctrl(-50,50,50,-50);
        }
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            ctrl(50,-50,-50,50);
        }
    }
    while(analog(1)>thresh1 || analog(0)>thresh0)
    {
        ctrl(50,50,50,50);
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            ctrl(-50,50,50,-50);
        }
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            ctrl(50,-50,-50,50);
        }
    }
}

};
class servo : public mec
{
public:
void servox(int port,int final,int time)  
{
    ao();
    enable_servo(port);
    int pos = get_servo_position(port);
    double mssleep;
    int distance;
    if(pos>final){
        distance = pos - final;
        mssleep = time/distance;
    }
    else if(pos<final){
        distance = final - pos;
        mssleep = time/distance;
    }
    while(pos<final)
    {
        pos+=1;
        set_servo_position(port, pos);
        msleep(mssleep);
    }
    while(pos>final)
    {
        pos-=1;
        set_servo_position(port, pos);
        msleep(mssleep);
    }
    disable_servo(port);
}
};


class gyro : public mpc
{
public:
void alphafwd(int speed, int cm)
{

    //about 53 ticks per cm
    int ticks=cm*53;

    int tickInterval=ticks/1;

    int bias12=speed*1.07223476298;//speed*1.69801980198;//to be fixed
    int bias03=speed*2;//speed*1.68965517241;//to be fixed


    int gmpc0=gmpc(0);
    int gmpc1=gmpc(1);
    int gmpc2=gmpc(2);
    int gmpc3=gmpc(3);

    for(int i=0; i<tickInterval; i++)
    {

        while((gmpc(0)<((gmpc0+ticks)-bias03) && gmpc(3)<((gmpc3+ticks)-bias03)) || (gmpc(1)<((gmpc1+ticks)-bias12) && gmpc(2)<((gmpc2+ticks)-bias12)))
        {
            if(gmpc(0)<((gmpc0+ticks)-bias03) && gmpc(3)<((gmpc3+ticks)-bias03) && gmpc(1)<((gmpc1+ticks)-bias12) && gmpc(2)<((gmpc2+ticks)-bias12))
            {
                while(gmpc(0)<((gmpc0+ticks)-bias03) && gmpc(3)<((gmpc3+ticks)-bias03) && gmpc(1)<((gmpc1+ticks)-bias12) && gmpc(2)<((gmpc2+ticks)-bias12))
                {

                    motor(0,speed);
                    motor(3,speed);
                    motor(1,speed);
                    motor(2,speed);
                }
            }

            if(gmpc(0)<((gmpc0+ticks)-bias03) && gmpc(3)<((gmpc3+ticks)-bias03))
            {
                while(gmpc(0)<((gmpc0+ticks)-bias03) && gmpc(3)<((gmpc3+ticks)-bias03))
                {
                    motor(0,speed);
                    motor(3,speed);

                }
            }

            if(gmpc(1)<((gmpc1+ticks)-bias12) && gmpc(2)<((gmpc2+ticks)-bias12))
            {
                while(gmpc(1)<((gmpc1+ticks)-bias12) && gmpc(2)<((gmpc2+ticks)-bias12))
                {
                    motor(1,speed);
                    motor(2,speed);
                }
            }

        }

    }
}



void calib_gyro_alpha()
{
    cmpc(0);
    cmpc(1);
    cmpc(2);
    cmpc(3);
}
void align_gyro_alpha()
{
    ao();

    int speed=20;
      //speed*1.68965517241;//needs fix

    while (((gmpc(0)<(0-bias03) && gmpc(3)<(0-bias03)) || (gmpc(0)>(0+bias03) && gmpc(3)>(0+bias03))) && ((gmpc(1)<(0-bias12) && gmpc(2)<(0-bias12)) || (gmpc(1)>(0+bias12) && gmpc(2)>(0+bias12))))
    {

        if ((gmpc(0)<(0-bias03) && gmpc(3)<(0-bias03)))//fwd rmotors 
        {
            while (gmpc(0)<(0-bias03) && gmpc(3)<(0-bias03))
            {
                ao();
                motor(3,speed);
                motor(0,speed);
            }

        }
        if ((gmpc(0)>(0-bias03) && gmpc(3)>(0-bias03)))//bwd rmotors 
        {
            while (gmpc(0)>(0-bias03) && gmpc(3)>(0-bias03))
            {
                ao();
                motor(3,-speed);
                motor(0,-speed);
            }

        }
        if ((gmpc(1)>(0-bias12) && gmpc(2)>(0-bias12)))//bwd lmotors 
        {
            while ((gmpc(1)>(0-bias12) && gmpc(2)>(0-bias12))) 
            {
                ao();
                motor(1,-speed);
                motor(2,-speed);
            }

        }
        if ((gmpc(1)<(0-bias12) && gmpc(2)<(0-bias12)))//fwd lmotors 
        {
            while ((gmpc(1)<(0-bias12) && gmpc(2)<(0-bias12))) 
            {
                ao();
                motor(1,speed);
                motor(2,speed);
            }

        }


    }

}

void align_gyro_alpha2(double a)
{

    int speed=25;
    bool broadcast=false;




    int average=((gmpc0+gmpc1)/2);

    printf("backslash\\%d\\\n",average);

    while ((gmpc(0)<gmpc2 && gmpc(3)<gmpc2) || (gmpc(1)<gmpc3 && gmpc(2)<gmpc3))
    {
        for(int i=0;i<2;i++)
        {
            while(broadcast==false)
            {
                printf("\\broadcast: %d\\\n",broadcast);

                //
                if(gmpc(1)<gmpc3 && gmpc(2)<gmpc3)
                {
                    while(gmpc(1)<average && gmpc(2)<average)
                    {
                        ao();
                        motor(1,speed);
                        motor(2,speed);


                    }
                    while(gmpc(0)>average && gmpc(3)>average)
                    {
                        ao();
                        motor(0,-speed);
                        motor(3,-speed);
                        broadcast=false;

                    }

                }
                //

                //
                if(gmpc(0)<gmpc2 && gmpc(3)<gmpc2)
                {
                    while(gmpc(0)<average && gmpc(3)<average)
                    {
                        ao();
                        motor(0,speed);
                        motor(3,speed);



                    }
                    while(gmpc(1)>average && gmpc(2)>average)
                    {
                        ao();
                        motor(1,-speed);
                        motor(2,-speed);
                        broadcast=false;
                    }


                }
                //
            }


        }


    }



}
};
class cam
{
public:
void snap()
{
    int xleft_threshold = 170;
    int xright_threshold = 310;

    camera_load_config("failure.conf");
    camera_open();
    for (int i = 0; i <15; i ++)
    {
        camera_update();
        if (get_object_center_x(0, 0) < xleft_threshold) {
            printf("its on the left");
        }
        else if (get_object_center_x(0, 0) > xright_threshold) {
            printf("its on the right");
        }
        else {
            printf("Its in the middle");
        }
        msleep(5000);
    }
}
};
class thr
{

};
class other
{

};
