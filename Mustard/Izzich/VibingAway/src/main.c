#include <kipr/wombat.h>

int initalSnap()
{
    int xleft_threshold = 170;
    int xright_threshold = 330;
    
    camera_load_config("failure.conf");
    camera_open();
    int pinkpos;
    int bluepos;
    int greenpos;
    int left = 0;
    int middle = 0;
    int right = 0;
    camera_update();
    if (get_object_center_x(0, 0) < xleft_threshold) {
        printf("Pink is on the left");
        pinkpos = 1280;
        left = 1;
    }
    else if (get_object_center_x(0, 0) > xright_threshold) {
        printf("Pink is on the right");
        pinkpos = 897;
        right = 1;
    }
    else {
        printf("Pink is in the middle");
        pinkpos = 566;
        middle = 1;
    }
    if (get_object_center_x(1, 0) < xleft_threshold) {
        printf("Blue is on the left");
        bluepos = 1280;
        left = 1;
    }
    else if (get_object_center_x(1, 0) > xright_threshold) {
        printf("Blue is on the right");
        bluepos = 897;
        right = 1;
    }
    else {
        printf("Blue is in the middle");
        bluepos = 566;
        middle = 1;
    }
    if (left==0) {
        printf("Green is on the left");
        greenpos = 1280;
    }
    else if (right==0) {
        printf("Green is on the right");
        greenpos = 897;
    }
    else {
        printf("Green is on the middle");
        greenpos = 566;
    }
    
    /*
    camera_load_config("find_red.conf");
    camera_open();
    
    for (int i = 0; i < 15; i++) {
        camera_update();
        if (get_object_count(0) > 3) {
            printf("RED!!!!!!")
        }
        else () {
            printf("NOPE!!!!!!")
        }
        msleep(1000);
    }
    */
    camera_close();
    return pos;
}
