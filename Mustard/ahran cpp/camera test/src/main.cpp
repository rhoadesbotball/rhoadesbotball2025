#include <kipr/wombat.h>
#include <iostream>


void snap4(int* x)
{
    camera_load_config("failure");
    camera_open();
    camera_update();
    int p = get_object_center_x(2, 0);
    int b = get_object_center_x(1, 6);
    int g = get_object_center_x(2, 3);
    camera_close();

    std::cout<<p<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<g<<std::endl;
    std::cout<<"bruh"<<std::endl;

    int pinkpos,bluepos,greenpos;

    auto checkpos2=[=,&pinkpos,&bluepos,&greenpos]()->void{
        if(p<b && p<g){
            pinkpos=1200;
            if(b<g){
                bluepos=100;
                greenpos=503;
            }
            else{
                bluepos=503;
                greenpos=875;
            }
        }
        if(b<p && b<g){
            bluepos=120;
            if(p<g){
                pinkpos=875;
                greenpos=503;
            }
            else{
                pinkpos=503;
                greenpos=875;
            }
        }
        if(g<b && g<p){
            greenpos=1200;
            if(b<p){
                bluepos=875;
                pinkpos=503;
            }
            else{
                bluepos=503;
                pinkpos=875;
            }
        }


    };
    checkpos2();
    x[0]=pinkpos;
    x[1]=bluepos;							
    x[2]=greenpos;
    
}


int main()
{
    int* x=new int[3];
	snap4(x);
    
    
    std::cout<<x[2]<<std::endl;
    std::cout<<x[1]<<std::endl;
    std::cout<<x[2]<<std::endl;
    




    
    return 0;
}
