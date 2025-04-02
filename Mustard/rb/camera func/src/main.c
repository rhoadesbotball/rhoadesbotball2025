#include <kipr/wombat.h>
#include <stdbool.h>
int main()
{
   	camera_load_config("failure");
    bool pinkIsHere = false;
    int pinkpos;
    camera_open();
    camera_update();
    if(get_object_count(0)>0)
    {
        pinkIsHere = true;
        if(get_object_center_x(0,0) >80)
        {
            pinkpos = 2;
        }
        else
        {
            pinkpos = 1;
        }
    }
    return 0;
}
