#include <kipr/wombat.h>

int main()
{
    int clicked = 0;
    while (clicked == 0){
        msleep(10);
        clicked = a_button();
    }
    printf("Yay i've been clicked");
    motor(0, 100);
    motor(2, 100);
    msleep(1000);
    return 0;
}
