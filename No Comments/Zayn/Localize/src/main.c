#include <kipr/wombat.h>
void localize();
int main()
{

    return 0;
}

void localize()
{
    while((analog(1)<3350) || (analog(0)<3350))
    {
        if((analog(1)<3350) || (analog(0)>3350))
        {
            
            motor(3,0);
            motor(3,30);
        }
        else if((analog(1)>3350) || (analog(0)<3350))
        {
            motor(3,0);
            motor(0,30);
        }
        else
        {
            motor(3,0);
            motor(0,30);
        }
    }while((analog(1)<3350) || (analog(0)<3350)
            
        
        
        