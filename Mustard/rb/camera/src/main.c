#include <kipr/wombat.h>
//0 pink
//1 blue
//2 green
//servo 1: turning
//servo 0: cup grabber
//servo 2: open/close
// servo 3 up
void camera();
int servo1 = 0;
int main()
{
    camera();
    return 0;
}
void camera()
{
    camera_load_config("failure");
    camera_open();
    camera_update();
    int p = get_object_center_x(0,0);
    int b = get_object_center_x(1,0);
    int g = get_object_center_x(2,0);
    if(p<b && p<g)
    {
        printf("p on left\n");
        servo1 = 1169;
        // cup claw up down: 851
        // up/down drink 1817
        // open: 2046
        
    }
    else if(p>g && p>b)
    {
        printf("p on right\n");
    }
    else
    {
        printf("p in middle\n");
    }
}