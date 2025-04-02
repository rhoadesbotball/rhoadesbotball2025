#include <kipr/wombat.h>
void forward(int speed, double time);
void left(int speed1, double time1);
int main()
{
    left(70, 5000);
    return 0;
}
void forward(int speed, double time)
{
    motor(0, speed);
    motor(1, speed);
    motor(2, speed);
    motor(3, speed);
    msleep(time);
}
void left(int speed1, double time1)
{
    motor(0, speed1 - 10);
    motor(2, speed1);
    motor(3, -speed1);
    motor(1, -speed1);
    msleep(time1);
}
void right(int speed2, double time2)
{
    motor(0, speed2 - 10);
    motor(2, speed2);
    motor(3, -speed2);
    motor(1, -speed2);
    msleep(time2);
}
