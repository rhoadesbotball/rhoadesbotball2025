void SSU(int port, int time, int final)// servo set
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
void SSUS(int port, int time, int final)
{
    enable_servo(port);
    int pos = get_servo_position(port);
    double mssleep;
    int distance;
    if(pos>final)
    {
        distance = pos - final;
        mssleep = time/distance;
    }
    else if(pos<final)
    {
        distance = final - pos;
        mssleep = time/distance;
    }
    while(pos<final)
    {
        freeze(0);
        freeze(3);
        pos+=1;
        set_servo_position(port, pos);
        msleep(mssleep);
        motor(3,80);
        motor(0,0);
        msleep(1);
        motor(0,80);
        motor(3,0);
        msleep(1);

    }
    while(pos>final)
    {
        freeze(0);
        freeze(3);
        pos-=1;
        set_servo_position(port, pos);
        msleep(mssleep);
        motor(3,80);
        motor(0,-66);
        msleep(1);
        motor(0,66);
        motor(3,-80);
        msleep(1);

    }
    disable_servo(port);
}
void drive(int distance)// perfect drive forward
{
    cmpc(0);
    while(gmpc(0)<distance-26)
    {
        motor(0,80);
        motor(3,80+adj);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
}
void driveb(int distance)
{
    cmpc(0);
    while(gmpc(0)>(distance*-1) + 26)
    {
        motor(0,-80);
        motor(3,-80-adj);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
}
void L90()// perfect left 90 degree turn
{
    cmpc(0);
    while(gmpc(0)<1200 - 26)
    {
        motor(0,50);
        motor(3,-50);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
}
void R90()
{
    cmpc(0);
    while(gmpc(0)>(1210*-1) + 26)
    {
        motor(0,-50);
        motor(3,50);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
}
void PL90()// perfect left 135 degree turn
{
    cmpc(3);
    while(gmpc(3)<3750-26)
    {
        motor(3,50);
        motor(0,0);
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}
void L45()// perfect left 45 turn
{
    cmpc(0);
    while(gmpc(0)<600 - 26)
    {
        motor(0,50);
        motor(3,-50);
    }

    motor(0,0);
    motor(3,0);
    msleep(500);
}