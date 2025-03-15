#include <kipr/wombat.h>
#include <iostream>
#include <stdbool.h>


int analog0b=analog(0);
int analog1b=analog(1);
int analog0w=analog(0);
int analog1w=analog(1);

int thresh0;
int thresh1;

void wait(long int time);
void lightarray();
void calib_analog();

int main()
{

    while(left_button()==0)
    {
        printf("hi");
        msleep(1000);
    }
    return 0;
}
void wait(long int time)
{
    motor(0,0);
    msleep(time);
}
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

void calib_analog_blk()
{
    
    while(left_button()==0)
    {
        printf("place sensors on black");
        printf("analog0 black value: %d",analog0b);
        printf("analog1 black value: %d",analog1b);
        
        console_clear();
    }
    while(left_button()==1)
    {
       analog0b=analog(0);
       analog1b=analog(1);
       break;
    }
    
    
    
    


}
void calib_analog_w()
{
    
    while(left_button()==0)
    {
        printf("place sensors on white");
        printf("analog0 white value: %d",analog0w);
        printf("analog1 white value: %d",analog1w);
        
        console_clear();
    }
    while(left_button()==1)
    {
       analog0w=analog(0);
       analog1w=analog(1);
       break;
    }
    
    
    
    


}
void calib_analog()
{
    calib_analog_blk();
    calib_analog_w();
    
    thresh0=((analog0b+analog0w)/2)+200;
    thresh1=((analog1b+analog1w)/2)+200;
    
}









/*

                 |       |
                 |       |
                 /       \
                /         \
               /           \
              (   _______   )
               \  |     |  /
                \ |     | /
                 _________
















*/