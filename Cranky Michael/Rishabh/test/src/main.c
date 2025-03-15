#include <kipr/wombat.h>
#include <alpha2.h>
int main()
{
    /*calib();
    save();
    mpcdrive12(70, 31);*/
    //alignws();
    /*calib();
    motor(0,30);
    motor(3,80);
    msleep(1000);
    align();*/
    //plf(80, r, 3000, 30);
    calib();
    motor(0,30);
    motor(3,80);
    msleep(1000);
    save();
    printf("%d\n", mpc0);
    printf("%d\n", mpc3);
    calib();
    motor(0,30);
    motor(3,80);
    msleep(1000);
    alignws();
    //compassdrive(0,0);
    return 0;
}
