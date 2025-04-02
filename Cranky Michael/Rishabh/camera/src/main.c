#include <kipr/wombat.h>

int main()
{
    int stop = 0;
    int x;
    int y;
    camera_load_config("ethan");
    camera_open();
    while(stop==0)
    {
        camera_update();
        if(get_object_count(0) > 0)
        {
            x = get_object_center_x(0,0);
            y = get_object_center_x(0,0);
            printf("The center of the object is (%d,%d).\n",x,y);
        }
        if(get_object_count(0) > 0)
        {
            if(get_object_center_x(0,0)<79)
            {
                motor(0,35);
                motor(3,-25);
            }
            else if(get_object_center_x(0,0)>81)
            {
                motor(0,-25);
                motor(3,35);
            }
            else
            {
                stop = 1;
                motor(0,0);
                motor(3,0);
                msleep(25);
                if(get_object_count(0)>0)
                {
                    x=get_object_center_x(0,0);
                    y=get_object_center_y(0,0);
                    printf("The center of the object is (%d,%d).\n",x,y);
                }
            }
        }
    }
    stop = 0;
    while(stop == 0)
    {
        camera_update(); // hewoo wishabh ho;ao
        if(get_object_count(0) > 0)
        {
            x = get_object_center_x(0,0);
            y = get_object_center_x(0,0);
            printf("The center of the object is (%d,%d).\n",x,y);
        }
        if(get_object_count(0) > 0)
        {
            if(get_object_center_x(0,0)<79 && get_object_center_y(0,0)>100)
            {
                motor(0,85);
                motor(3,70);
            }
            else if(get_object_center_x(0,0)>81 && get_object_center_y(0,0)>100)
            {
                motor(0,70);
                motor(3,85);
            }
            else if(get_object_center_y(0,0)>150)
            {
                motor(0,70);
                motor(3,70);
            }
            else
            {
                stop = 1;
            }
        }
    }
    stop = 0;
    while(stop==0)
    {
        camera_update();
        if(get_object_count(0) > 0)
        {
            x = get_object_center_x(0,0);
            y = get_object_center_x(0,0);
            printf("The center of the object is (%d,%d).\n",x,y);
        }
        if(get_object_count(0) > 0)
        {
            if(get_object_center_x(0,0)<79)
            {
                motor(0,35);
                motor(3,-25);
            }
            else if(get_object_center_x(0,0)>81)
            {
                motor(0,-25);
                motor(3,35);
            }
            else
            {
                stop = 1;
                motor(0,0);
                motor(3,0);
                msleep(25);
                if(get_object_count(0)>0)
                {
                    x=get_object_center_x(0,0);
                    y=get_object_center_y(0,0);
                    printf("The center of the object is (%d,%d).\n",x,y);
                }
            }
        }
    }
    return 0;
}
