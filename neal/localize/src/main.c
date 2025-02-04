#include<kipr/wombat.h>
int main()

{
    void localize()
    {
        while(analog(1)<3700 || analog(0)<3700)
        {
            if(analog(1)<3700 && analog(0)>3700)
            {
                motor(0,0);
                motor(3,30);
                motor(2,30);
                motor(1,0);
            }
            else if(analog(1)>3700 && analog(0)<3700)
            {
                motor(3,0);
                motor(0,30);
                motor(1,30);
                motor(2,0);



            }
            else
            {
                motor(0,30);
                motor(3,30);
                motor(2,30);
                motor(1,30);


            }

        }
        while(analog(1)>3700 || analog(0)>3700)
        {
            if(analog(1)>3700 && analog(0)<3700)
            {

                motor(0,0);
                motor(3,30);
                motor(2,30);
                motor(1,0);
            }
            else if(analog(1)<3700 && analog(0)>3700)
            {
                motor(1,30);
                motor(2,0);
                motor(3,0);
                motor(0,30);

            }
            else
            {
                motor(3,30);
                motor(2,30);
                motor(1,30);
                motor(0,30);
            }
        }

    }
    void locback()
    {
        while(analog(1)<3700 || analog(0)<3700)
        {
            if(analog(1)<3700 && analog(0)>3700)
            {
                motor(0,30);
                motor(3,0);
                motor(2,0);
                motor(1,30);
            }
            else if(analog(1)>3700 && analog(0)<3700)
            {
                motor(3,30);
                motor(0,0);
                motor(1,0);
                motor(2,30);



            }
            else
            {
                motor(0,-30);
                motor(3,-30);
                motor(2,-30);
                motor(1,-30);


            }

        }
        while(analog(1)>3700 || analog(0)>3700)
        {
            if(analog(1)>3700 && analog(0)<3700)
            {

                motor(0,30);
                motor(3,0);
                motor(2,0);
                motor(1,30);
            }
            else if(analog(1)<3700 && analog(0)>3700)
            {
                motor(1,0);
                motor(2,30);
                motor(3,30);
                motor(0,0);

            }
            else
            {
                motor(3,-30);
                motor(2,-30);
                motor(1,-30);
                motor(0,-30);
            }
        }

    }
    
    
    localize();
    


    return 0;
}