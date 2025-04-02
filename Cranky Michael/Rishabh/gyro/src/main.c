
#include <kipr/wombat.h>
double bias;
double calibrate_gyro();
void drive_with_gyro(int speed, double time);
int main()
{
    printf("Hello World\n");
    calibrate_gyro();
    drive_with_gyro(-1200, 15); // misread this function, whoops
    return 0;
}
double calibrate_gyro()
{
    int i =0;
    bias =0.2;
    float avg = 0; // prevent integer division
    while(i<3000)
    {
        int gyro_z_val = gyro_z(); // if its off by x per poll, we want to poll less
        avg+=gyro_z_val;
        msleep(10); // increase time by a bit, just in case
        i++;
        printf("Gyro Z: %d\n", gyro_z_val);
    }
    bias=avg/3000.0;
    printf("New Bias: %lf\n", bias);
    return bias;
}
void drive_with_gyro(int speed, double time)
{
    double startTime = seconds();
    double theta = 0;
    int right_motor = 3;
    int left_motor = 0;
    while(seconds() - startTime < time)
    {
        if(theta<10 && theta>-10) // +- 10 degrees, rather than 1000
        {
            mav(right_motor, speed);
            mav(left_motor, speed);
        }
        else if(theta<10)
        {
            mav(right_motor, speed+100);
            mav(left_motor, speed-100);
        }
        else
        {
            mav(right_motor, speed-100);
            mav(left_motor, speed+100);
        }
        msleep(10);
        theta += ((gyro_z()-bias)*(3.0/245.0)/* this converts to degrees... idk why its needed tbh */);
        printf("%f\n", theta);
    }
    ao();
}