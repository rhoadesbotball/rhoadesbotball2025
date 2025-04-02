#include <kipr/wombat.h>
int main()
{
    // All Ideas Go To Ahran
    int white0;
    int black0;
    int white1;
    int black1;
    while(digital(0)==0)
    {
        white0 = analog(0);
        printf("Show me white and press digital 0\n");
        printf("Analog: %d\n", white0);
        msleep(10);
        console_clear();
    }
    printf("Analog: %d\n", white0);
    msleep(1000);
    while(digital(0)==0)
    {
        black0 = analog(0);
        printf("Show me black and press digital 0\n");
        printf("Analog: %d\n", black0);
        msleep(10);
        console_clear();
    }
    printf("Analog: %d\n", black0);
    msleep(1000);
    while(digital(0)==0)
    {
        white1 = analog(1);
        printf("Show me white and press digital 0\n");
        printf("Analog: %d\n", white1);
        msleep(10);
        console_clear();
    }
    printf("Analog: %d\n", white1);
    msleep(1000);
    while(digital(0)==0)
    {
        black1 = analog(1);
        printf("Show me black and press digital 0\n");
        printf("Analog: %d\n", black1);
        msleep(10);
        console_clear();
    }
    printf("Analog: %d\n", black1);
    console_clear();
    int finalt0 = (white0+black0)/2;
    int finalt1 = (white1+black1)/2;
    printf("Analog: %d\n", finalt0);
    printf("Analog: %d\n", finalt1);
    return 0;
}
