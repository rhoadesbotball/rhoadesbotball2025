#include <kipr/wombat.h>

int main()
{
    void servo(int port,int time, int final)
    {
        enable_servo(port);
        int pos=get_servo_position(port);
        while(pos>final)
        {
            pos=pos-10;
            set_servo_position(port,pos);
            msleep(time);
            
                
        }
        while(pos<final)
        {
            pos=pos+10;
            set_servo_position(port,pos);
            msleep(time);
           
        }
        
        disable_servo(port);
    }
    
    return 0;
}
