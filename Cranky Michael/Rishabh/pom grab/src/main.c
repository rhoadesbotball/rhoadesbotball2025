#include <kipr/wombat.h>
void SSU(int port, int time, int final);
int main()
{
    SSU(0, 1600, 950);
    while(gmpc(1)<15450)
    {
        motor(1,80);
    }
    freeze(1);
    SSU(0, 1600, 1690);
    return 0;
}
void SSU(int port, int time, int final)
{
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