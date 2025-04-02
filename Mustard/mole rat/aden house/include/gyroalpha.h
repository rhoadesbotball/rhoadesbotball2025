#include <kipr/wombat.h>
#include <alpha.h>

void gyro_alpha(int speed, int ticks);
{
    int tickInterval=ticks/100;
    
    int bias12=0;
    int bias03=0;
    

    cmpc(0);
    cmpc(1);
    cmpc(2);
    cmpc(3);
    

    for(int i=0; i<tickInterval;, i++)
    {
        
        while(gmpc(0)<(tickInterval-bias03) && gmpc(3)<(tickInterval-bias03) || gmpc(1)<(tickInterval-bias12) && gmpc(2)<(tickInterval-bias12))
        {
            if(gmpc(0)<(tickInterval-bias03) && gmpc(3)<(tickInterval-bias03) && gmpc(1)<(tickInterval-bias12) && gmpc(2)<(tickInterval-bias12))
            {
                while(gmpc(0)<(tickInterval-bias03) && gmpc(3)<(tickInterval-bias03) && gmpc(1)<(tickInterval-bias12) && gmpc(2)<(tickInterval-bias12))
                {
                mecwsleep(speed,speed,speed,speed);
                }
            }
            
            if(gmpc(0)<(tickInterval-bias03) && gmpc(3)<(tickInterval-bias03))
            {
              while(gmpc(0)<(tickInterval-bias03) && gmpc(3)<(tickInterval-bias03))
              {
              motor(0,speed);
              motor(3,speed);
              }
            }
            
            if(gmpc(1)<(tickInterval-bias12) && gmpc(2)<(tickInterval-bias12))
            {
              while(gmpc(1)<(tickInterval-bias12) && gmpc(2)<(tickInterval-bias12))
              {
              motor(1,speed);
              motor(2,speed);
              }
            }
            
        }
    }


}