#include <kipr/wombat.h>

int main()
{
    void strafright(int time,int speed)
    {
        motor(0,-speed);
        motor(1,speed);
        motor(2,-speed);
        motor(3,speed);
        msleep(time);
        
    }
    void strafleft(int timeleft, int speedleft)
    {
        motor(0,speedleft);
        motor(1,-speedleft);
        motor(2,speedleft);
        motor(3,-speedleft);
        msleep(timeleft);
         
    }
    void forward(int time,int speed)
    {
        motor(0,speed);
        motor(1,speed);
        motor(2,speed);
        motor(3,speed);
        msleep(time);
    }
    void backward(int timeback,int speedback)
    {
        motor(0,-speedback);
        motor(1,-speedback);
        motor(2,-speedback);
        motor(3,-speedback);
        msleep(timeback);
    }
    
    strafright(1000,30);
    strafleft(1000,30);
    forward(2000,30);
    backward(2000,30);
    return 0;
}
