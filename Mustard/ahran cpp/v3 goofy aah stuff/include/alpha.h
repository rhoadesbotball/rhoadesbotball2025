#include <array>
#include <kipr/wombat.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <array>

using string=std::string;

// declares vars for funcs
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

int thresh0=3170;
int thresh1=3170;

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

int s0;
int s1;
int s2;
int s3;


class mec// all funcs to do with mecanum wheels/basic movement
{
    public:


    void fwd(int speed, int time)// moves forward
    {
        motor(0,speed);
        motor(1,speed);
        motor(2,speed);
        motor(3,speed);
        msleep(time);
    }
    void bwd(int speed, int time)// moves backward
    {
        motor(0,-speed);
        motor(1,-speed);
        motor(2,-speed);
        motor(3,-speed);
        msleep(time);
    }
    void control(int speed0,int speed1,int speed2,int speed3,int time)// a function to control speeds of all four motors and msleep
    {
        motor(0,speed0);
        motor(1,speed1);
        motor(2,speed2);
        motor(3,speed3);
        msleep(time);  
    }
    void control(int speed0,int speed1,int speed2,int speed3)// override of control w/o time 
    {
        motor(0,speed0);
        motor(1,speed1);
        motor(2,speed2);
        motor(3,speed3);

    }
    void ctrl(int speed0,int speed1,int speed2,int speed3)//override of control for faster typing
    {
        motor(0,speed0);
        motor(1,speed1);
        motor(2,speed2);
        motor(3,speed3);

    }
    void ctrl(int speed0,int speed1,int speed2,int speed3,int time)// override of ctrl w/o time
    {
        motor(0,speed0);
        motor(1,speed1);
        motor(2,speed2);
        motor(3,speed3);
        msleep(time);  
    }
    void mecwsleep(int speed0,int speed1,int speed2,int speed3)// ctrl without time(was sused for transfer from c to c++
    {
        motor(0,speed0);
        motor(1,speed1);
        motor(2,speed2);
        motor(3,speed3);
    }
    void wait(int time)// all motors sleep for an indicated time
    {
    ctrl(0,0,0,0,time);
    }


void diag(int direction, int speed, int sleep)// moves diagonally(using mecanum wheels) with specifications for speed, time, and direction
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
void strafe(int direction, int speed, int duration)//strafe function 
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
void strafe2(int direction, int speed, int duration)// 2nd version of strafe(used with script gyro
{
s0=gmpc(0);
s1=gmpc(1);
s2=gmpc(2);
s3=gmpc(3);


    if (direction==r)
    {
        control(-speed,speed,-speed,speed,duration);
    }
    if (direction==l)
    {
        control(speed,-speed,speed,-speed,duration);
    }
    cmpc(0); 
    cmpc(1); 
    cmpc(2); 
    cmpc(3); 

}
void strafe2(int direction, int speed)// override of strafe2 w/o time
{
s0=gmpc(0);
s1=gmpc(1);
s2=gmpc(2);
s3=gmpc(3);


    if (direction==r)
    {
        control(-speed,speed,-speed,speed);
    }
    if (direction==l)
    {
        control(speed,-speed,speed,-speed);
    }
    cmpc(0); 
    cmpc(1); 
    cmpc(2); 
    cmpc(3); 

}
void bwdwheelstrafe(int speed,long int time)//strafes with only back wheels
{
ctrl(0,0,speed,-speed,time);
}
};
class shake : public mec// inherired shake class from class mec
{
public:
void pvtshakey(int wheel,int times)//shakes robot by pivoting
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
gmpc0=gmpc(0)-bias03;
gmpc1=gmpc(1)-bias12;
gmpc2=gmpc(2)-bias12;
gmpc3=gmpc(3)-bias03;

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
void lightarray()
{
    printf("                 |       |\n");
    printf("                 |       |\n");
    printf("                /        \\\n");
    printf("               /          \\\n");
    printf("              /            \\\n");
    printf("             (     _____    )\n");
    printf("              \\  |     |   /\n");
    printf("               \\ |     |  /\n");
    printf("                __________\n");


}

void calib_analog()
{
    lightarray();
    bloki();
    bwd(25,500);
    analog0b=analog(0);
    analog1b=analog(1);

    bwd(25,1000);

    analog0w=analog(0);
    analog1w=analog(1);

    thresh0=((analog0b+analog0w)/2)+300;
    thresh1=((analog1b+analog1w)/2)+300;

    printf("thresh0:%d",thresh0);
    printf("thresh1:%d",thresh1);




}


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


class gyro : public mec
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

void align_gyro_alpha2()
{

    int speed=25;
    bool broadcast=false;




    int average=((gmpc0+gmpc1)/2);

    printf("backslash\\%d\\\n",average);

    while ((gmpc(0)<gmpc1 && gmpc(3)<gmpc1) || (gmpc(1)<gmpc2 && gmpc(2)<gmpc2))
    {
        for(int i=0;i<2;i++)
        {
            while(broadcast==false)
            {
                printf("\\broadcast: %d\\\n",broadcast);

                //
                if(gmpc(1)<gmpc0 && gmpc(2)<gmpc0)
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
                        broadcast=true;

                    }

                }
                //

                //
                if(gmpc(0)<gmpc1 && gmpc(3)<gmpc1)
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
                        broadcast=true;
                    }


                }
                //
            }


        }


    }



}
void align_gyro_alpha3()
{

    int speed=25;
    bool broadcast=false;









    while ((gmpc(0)<gmpc1 && gmpc(3)<gmpc1) || (gmpc(1)<gmpc1 && gmpc(2)<gmpc1))
    {
        for(int i=0;i<2;i++)
        {
            while(broadcast==false)
            {
                printf("\\broadcast: %d\\\n",broadcast);

                //
                if(gmpc(1)<gmpc1 && gmpc(2)<gmpc1)
                {
                    while(gmpc(1)<gmpc1 && gmpc(2)<gmpc1)
                    {
                        ao();
                        motor(1,speed);
                        motor(2,speed);
                        broadcast=true;


                    }


                }
                //

                //
                if(gmpc(0)<gmpc1 && gmpc(3)<gmpc1)
                {
                    while(gmpc(0)<gmpc1 && gmpc(3)<gmpc1)
                    {
                        ao();
                        motor(0,speed);
                        motor(3,speed);
                        broadcast=true;



                    }



                }
                //
            }


        }


    }



}
void align_gyro_alpha4()
{

    int speed=25;
    bool broadcast=false;

    int sgmpc0=gmpc(0)+bias03;
    int sgmpc1=gmpc(1)+bias12;
    int sgmpc2=gmpc(2)+bias12;
    int sgmpc3=gmpc(3)+bias03;



    while ((s0<s1 && s3<s1) || (s1<s0 && s2<s0))
    {

        for(int i=0;i<2;i++)
        {
            while(broadcast==false)
            {
                printf("\\broadcast: %d\\\n",broadcast);

                //
                if(s1<s0 && s2<s0)
                {
                    while(s1<s0 && s2<s0)
                    {
                        ao();
                        motor(1,speed);
                        motor(2,speed);
                        broadcast=true;

                        s1+=(gmpc(1)-sgmpc1);
                        s2+=(gmpc(2)-sgmpc2);





                    }


                }
                //

                //
                if(s0<s1 && s3<s1)
                {
                    while(s0<s1 && s3<s1)
                    {
                        ao();
                        motor(0,speed);
                        motor(3,speed);
                        broadcast=true;

                        s0+=gmpc(0)-sgmpc0;
                        s3+=gmpc(3)-sgmpc3;





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
		/*int xleft_threshold;
        int xright_threshold;
		cam(int xl,int xr){
			xleft_threshold=xl;
			xright_threshold=xr;
		}*/
		int* snap()
		{
        
            int xleft_threshold=330;
        	int xright_threshold=420;
            printf("here");
			camera_load_config("failure");
            printf("there");
            camera_open();
            printf("yippee");
    		int pinkpos;
    		int bluepos;
    		int greenpos;

    		int left = 0;
    		int middle = 0;
    		int right = 0;
    		camera_update();
            printf("%d\n", xleft_threshold);
            printf("%d\n", xright_threshold);
    		if (get_object_center_x(0, 0) < xleft_threshold) {
        		printf("Pink is on the left");
        		pinkpos = 1200;
        		left = 1;
    		}
    		else if (get_object_center_x(0, 0) > xright_threshold) {
        		printf("Pink is on the right");
        		pinkpos = 503;
        		right = 1;
   			}
    		else {
        		printf("Pink is in the middle");
        		pinkpos = 875;
        		middle = 1;
    		}
    		if (get_object_center_x(1, 0) < xleft_threshold) {
        		printf("Blue is on the left");
        		bluepos = 1200;
        		left = 1;
    		}
    		else if (get_object_center_x(1, 0) > xright_threshold) {
        		printf("Blue is on the right");
        		bluepos = 503;
        		right = 1;
    		}
    		else {
        		printf("Blue is in the middle");
        		bluepos = 875;
        		middle = 1;
    		}
    		if (left==0) {
        		printf("Green is on the left");
        		greenpos = 1200;
    		}
    		else if (right==0) {
        		printf("Green is on the right");
        		greenpos = 503;
    		}
    		else {
        		printf("Green is on the middle");
        		greenpos = 875;
    		}
    		//printf("Pink: %d", get_object_center_x(0,0));
    		//printf("Blue: %d", get_object_center_x(1,0));
    		camera_close();

    		printf("%d\n", pinkpos);
    		printf("%d\n", bluepos);
    		printf("%d\n", greenpos);
            
            int *deltapos=new int[3];
            deltapos[0]=pinkpos;
            deltapos[1]=bluepos;
            deltapos[2]=greenpos;
            
            return deltapos;



			/*camera_load_config("failure");
            camera_open();
            camera_update();
            int pink = get_object_center_x(0, 0);
			int blue = get_object_center_x(1, 0);
            int green = get_object_center_x(2, 0);

            int valueArr[]={pink,blue,green};

            auto sortArr = [&](int Arr[],int size)->int*{
            static int arr[3];
            for(int l=0; l<size; l++)
            {
            arr[size]=Arr[size];
            }
            int temp;
                for(int i=0;i<size;i++)
                {
            	    for(int j=0;j<size;j++)
                    {
                		if (arr[j]>arr[j+1])
                		{
                   	    temp=arr[j];
                    	arr[j]=arr[j+1];
                    	arr[j+1]=temp;
                		}
                    }

            	}
                return arr;
            }; 
            int* ptrStatic=sortArr(valueArr,3);

            int ptrStatic0=ptrStatic[0];
            int ptrStatic1=ptrStatic[1];
            int ptrStatic2=ptrStatic[2];

            if(pink==ptrStatic0){std::cout<<"pink is on right"<<std::endl;}
            else if(pink==ptrStatic1){std::cout<<"pink is in middle"<<std::endl;}
            else if(pink==ptrStatic2){std::cout<<"pink is on left"<<std::endl;}

            if(blue==ptrStatic0){std::cout<<"blue is on right"<<std::endl;}
            else if(blue==ptrStatic1){std::cout<<"blue is in middle"<<std::endl;}
            else if(blue==ptrStatic2){std::cout<<"blue is on left"<<std::endl;}

            if(green==ptrStatic0){std::cout<<"green is on right"<<std::endl;}
            else if(green==ptrStatic1){std::cout<<"green is in middle"<<std::endl;}
            else if(green==ptrStatic2){std::cout<<"green is on left"<<std::endl;}*/


            /*cup pinkcup;
            pinkcup.pos=pink;
            pinkcup.color="pink";

            cup bluecup;
            bluecup.pos=blue;
            bluecup.color="blue";

            cup greencup;
            greencup.pos=green;
            greencup.color="green";

            auto checkpos=[&](cup cup1,cup cup2,cup cup3)->cup*{
            	cup* arr=new cup[3];//array of structs
                arr[0]=cup1;
                arr[1]=cup2;
                arr[2]=cup3;


            int temp;
            int size=3;
                for(int i=0;i<size;i++)
                {
            	    for(int j=0;j<size;j++)
                    {
                		if (arr[(j)].pos>arr[(j+1)].pos)
                		{
                   	    temp=arr[(j)].pos;
                    	arr[(j)].pos=arr[(j+1)].pos;
                    	arr[(j+1)].pos=temp;
                		}
                    }

            	}
                return arr;

            };
            auto* arr=checkpos(pinkcup,bluecup,greencup);

			int pinkpos;
            int bluepos;
            int greenpos;
            int *echopos=new int[3];

            //checking which is on left
            if(arr[0].color=="pink")
            {
            std::cout<<"pink is on the left"<<std::endl;
            pinkpos = 1200;
            echopos[0]=arr[0].pos;
            }
            if(arr[0].color=="blue")
            {
            std::cout<<"blue is on the left"<<std::endl;
            bluepos = 1200;
            echopos[0]=arr[0].pos;
            }
            if(arr[0].color=="green")
            {
            std::cout<<"green is on the left"<<std::endl;
            greenpos = 1200;
            echopos[0]=arr[0].pos;
            }

            //checking which is in middle
            if(arr[1].color=="pink")
            {
            std::cout<<"pink is on the middle"<<std::endl;
            pinkpos = 875;
            echopos[1]=arr[1].pos;
            }
            if(arr[1].color=="blue")
            {
            std::cout<<"blue is on the middle"<<std::endl;
            bluepos = 875;
            echopos[1]=arr[1].pos;
            }
            if(arr[1].color=="green")
            {
            std::cout<<"green is on the middle"<<std::endl;
            greenpos = 875;
            echopos[1]=arr[1].pos;
            }
            //checking which is on right
            if(arr[2].color=="pink")
            {
            std::cout<<"pink is on the right"<<std::endl;
            pinkpos = 503;
            echopos[2]=arr[2].pos;
            }
            if(arr[2].color=="blue")
            {
            std::cout<<"blue is on the right"<<std::endl;
            bluepos = 503;
            echopos[2]=arr[2].pos;
            }
            if(arr[2].color=="green")
            {
            std::cout<<"green is on the right"<<std::endl;
            greenpos = 503;
            echopos[2]=arr[2].pos;
            }
            
            

    		
    		return echopos;*/
		}
        
        
        
        
        
        
        
        
        
        
        
        
        ////////////////////////////////////////
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
       /* int* snap2()
        {
        	camera_load_config("failure");
            camera_open();
            camera_update();
            int pink = get_object_center_x(0, 0);
			int blue = get_object_center_x(1, 0);
            int green = get_object_center_x(2, 0);
            
            cup pinkcup;
            pinkcup.pos=pink;
            pinkcup.color='p';

            cup bluecup;
            bluecup.pos=blue;
            bluecup.color='b';

            cup greencup;
            greencup.pos=green;
            greencup.color='g';

            cup valueArr[]={pinkcup,bluecup,greencup};

            auto sortArr = [&](cup Arr[],int size)->cup*{
            static cup arr[3];
            for(int l=0; l<size; l++)
            {
            arr[size]=Arr[size];
            }
            int temp;
                for(int i=0;i<size;i++)
                {
            	    for(int j=0;j<size;j++)
                    {
                		if (arr[j].pos>arr[j+1].pos)
                		{
                   	    temp=arr[j].pos;
                    	arr[j].pos=arr[j+1].pos;
                    	arr[j+1].pos=temp;
                		}
                    }

            	}
                return arr;
            }; 
            
            ///////////////
            
            cup* ptrStatic=sortArr(valueArr,3);

            const int ptrStatic0=ptrStatic[0].pos;
            const int ptrStatic1=ptrStatic[1].pos;
            const int ptrStatic2=ptrStatic[2].pos;

            if(pink==ptrStatic0){std::cout<<"pink is on right"<<std::endl;}
            else if(pink==ptrStatic1){std::cout<<"pink is in middle"<<std::endl;}
            else if(pink==ptrStatic2){std::cout<<"pink is on left"<<std::endl;}

            if(blue==ptrStatic0){std::cout<<"blue is on right"<<std::endl;}
            else if(blue==ptrStatic1){std::cout<<"blue is in middle"<<std::endl;}
            else if(blue==ptrStatic2){std::cout<<"blue is on left"<<std::endl;}

            if(green==ptrStatic0){std::cout<<"green is on right"<<std::endl;}
            else if(green==ptrStatic1){std::cout<<"green is in middle"<<std::endl;}
            else if(green==ptrStatic2){std::cout<<"green is on left"<<std::endl;}



            auto checkpos=[&](cup cup1,cup cup2,cup cup3)->cup*{
            	cup* arr=new cup[3];//array of structs
                arr[0]=cup1;
                arr[1]=cup2;
                arr[2]=cup3;


            int temp;
            int size=3;
                for(int i=0;i<size;i++)
                {
            	    for(int j=0;j<size;j++)
                    {
                		if (arr[(j)].pos>arr[(j+1)].pos)
                		{
                   	    temp=arr[(j)].pos;
                    	arr[(j)].pos=arr[(j+1)].pos;
                    	arr[(j+1)].pos=temp;
                		}
                    }

            	}
                return arr;

            };
            auto* arr=checkpos(pinkcup,bluecup,greencup);

			int pinkpos;
            int bluepos;
            int greenpos;
            static int *echopos=new int[3];

            //checking which is on left
            if(arr[0].color=='p')
            {
            std::cout<<"pink is on the left"<<std::endl;
            pinkpos = 1200;
            echopos[0]=arr[0].pos;
            }
            if(arr[0].color=='b')
            {
            std::cout<<"blue is on the left"<<std::endl;
            bluepos = 1200;
            echopos[0]=arr[0].pos;
            }
            if(arr[0].color=='g')
            {
            std::cout<<"green is on the left"<<std::endl;
            greenpos = 1200;
            echopos[0]=arr[0].pos;
            }

            //checking which is in middle
            if(arr[1].color=='p')
            {
            std::cout<<"pink is on the middle"<<std::endl;
            pinkpos = 875;
            echopos[1]=arr[1].pos;
            }
            if(arr[1].color=='b')
            {
            std::cout<<"blue is on the middle"<<std::endl;
            bluepos = 875;
            echopos[1]=arr[1].pos;
            }
            if(arr[1].color=='g')
            {
            std::cout<<"green is on the middle"<<std::endl;
            greenpos = 875;
            echopos[1]=arr[1].pos;
            }
            
            //checking which is on right
            if(arr[2].color=='p')
            {
            std::cout<<"pink is on the right"<<std::endl;
            arr[2] = 503;
            echopos[2]=arr[2].pos;
            }
            if(arr[2].color=='b')
            {
            std::cout<<"blue is on the right"<<std::endl;
            arr[2] = 503;
            echopos[2]=arr[2].pos;
            }
            if(arr[2].color=='g')
            {
            std::cout<<"green is on the right"<<std::endl;
            arr[2] = 503;
            echopos[2]=arr[2].pos;
            }
            
            

    		
    		return echopos;

        }*/
        
        int* snap3()
        {
        	camera_load_config("failure");
            camera_open();
            camera_update();
            int p = get_object_center_x(0, 0);
			int b = get_object_center_x(1, 0);
            int g = get_object_center_x(2, 0);
            
            int* values=new int[3];
            values[0]=p;
            values[1]=b;
            values[2]=g;
            
            auto checkpos=[&](int arr[])->int*{
            
            int temp;
            int size=3;
                for(int i=0;i<size;i++)
                {
            	    for(int j=0;j<size;j++)
                    {
                		if (arr[(j)]>arr[(j+1)])
                		{
                   	    temp=arr[(j)];
                    	arr[(j)]=arr[(j+1)];
                    	arr[(j+1)]=temp;
                		}
                    }

            	}
                return arr;

            };
            int* arr=checkpos(values);
            
            if(arr[0]==p){std::cout<<"p on r\t"<<std::endl;}
            else if(arr[0]==b){std::cout<<"b on r\t"<<std::endl;}
            else if(arr[0]==g){std::cout<<"g on r\t"<<std::endl;}
            
            if(arr[1]==p){std::cout<<"p on m\t"<<std::endl;}
            else if(arr[1]==b){std::cout<<"b on m\t"<<std::endl;}
            else if(arr[1]==g){std::cout<<"g on m\t"<<std::endl;}
            
            if(arr[2]==p){std::cout<<"p on l\t"<<std::endl;}
            else if(arr[2]==b){std::cout<<"b on l\t"<<std::endl;}
            else if(arr[2]==g){std::cout<<"g on l\t"<<std::endl;}
            
            return arr;
            
            
        
        
        }
        
/*void snap4(int* x)
{
    camera_load_config("failure");
    camera_open();
    camera_update();
    int p = get_object_center_x(0, 0);
    int b = get_object_center_x(1, 0);
    int g = get_object_center_x(2, 0);
    camera_close();

    std::cout<<p<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<g<<std::endl;
    std::cout<<"bruh"<<std::endl;

    int pinkpos,bluepos,greenpos;
    //
    int r=450;
    int m=720;
    int l=1000;

    auto checkpos2=[=,&pinkpos]()->void{
        if(p<b && p<g){
            pinkpos=l;
            printf("p on l\n");
            if(b<g){
                bluepos=m;
                printf("b on m\n");
                greenpos=r;
                printf("g on r\n");
            }
            else{
                bluepos=r;
                printf("b on r\n");
                greenpos=m;
                printf("g on m\n");
            }
        }
        if(b<p && b<g){
            bluepos=l;
            printf("b on l\n");
            if(p<g){
                pinkpos=m;
                printf("p on m\n");
                greenpos=r;
                printf("g on r\n");
            }
            else{
                pinkpos=r;
                printf("p on r\n");
                greenpos=m;
                printf("g on m\n");
            }
        }
        if(g<b && g<p){
            greenpos=l;
            printf("g on l\n");
            if(b<p){
                bluepos=m;
                printf("b on m\n");
                pinkpos=r;
                printf("p on r\n");
            }
            else{
                bluepos=r;
                printf("b on r\n");
                pinkpos=m;
                printf("p on m\n");
            }
        }


    };
    checkpos2();
    x[0]=pinkpos;
    x[1]=bluepos;
    x[2]=greenpos;
    std::cout<<"pink: "<<x[0]<<std::endl;
    x[1]=bluepos;
    std::cout<<"blue: "<<x[1]<<std::endl;
    x[2]=greenpos;
    std::cout<<"green: "<<x[2]<<std::endl;
    
    //returners
    return;
    
    
}*/
char snap6(int &x)
{
    camera_load_config("failure");
    camera_open();
    camera_update();
    int p = get_object_center_x(0, 0);
    int b = get_object_center_x(1, 0);
    int g = get_object_center_x(2, 0);
    camera_close();

    std::cout<<p<<std::endl;

    int pinkpos;
    //
    

    auto checkpos2=[=,&pinkpos]()->void{
        if(p<b && p<g){
            pinkpos=l2;
            printf("p on l\n");
            
        }
        if(p>b && p>g){
            pinkpos=r2;
            printf("p on r\n");
            
        }
        if((b<p && p<g) || (g<p && p<b)){
            
            
            
                pinkpos=m;
                printf("p on m\n");
            
        }
        

    };
    checkpos2();
    x=pinkpos;
    std::cout<<"pink: "<<x<<std::endl;
    
    
    //returners
    if(pinkpos==l){return 'l';}
    if(pinkpos==m){return 'm';}
    if(pinkpos==r){return 'r';}
    
    
}
int snap5()
{
    camera_load_config("failure");
    camera_open();
    camera_update();
    int p = get_object_center_x(0, 0);
    int b = get_object_center_x(1, 0);
    int g = get_object_center_x(2, 0);
    camera_close();

    std::cout<<p<<std::endl;

    int pinkpos;
    //
    const int r=510;
    const int m=780;
    const int l=1210;

    auto checkpos2=[=,&pinkpos]()->void{
        if(p<b && p<g){
            pinkpos=l;
            printf("p on l\n");
            
        }
        if(p>b && p>g){
            pinkpos=r;
            printf("p on r\n");
            
        }
        if((b<p && p<g) || (g<p && p<b)){
            
            
            
                pinkpos=m;
                printf("p on m\n");
            
        }
        

    };
    checkpos2();
    int x=pinkpos;
    std::cout<<"pink: "<<x<<std::endl;
    
    
    //returners
    return x;
    
    
}



};
