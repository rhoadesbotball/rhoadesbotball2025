#include <kipr/wombat.h>

int main()
{
    motor(0,67.5);
    motor(2,-60);
    msleep(876);
    
    motor(0,77.5);
    motor(2,70);
    msleep(803);
    
    motor(0,-67.5);
    motor(2,-60);
    msleep(600.3);
    
    motor(0,-67.5);
    motor(2,70);
    msleep(800);
    
    motor(0,-77.5);
    motor(2,-70);
    msleep(1001);
    
    motor(0,77.5);
    motor(2,-70);
    msleep(876);
    
    motor(0,77.5);
    motor(2,70);
    msleep(502);
    
    return 0;
}
