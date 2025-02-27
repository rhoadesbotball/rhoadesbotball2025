#include <kipr/wombat.h>
#include<math.h>

int main()
{
    int py( double a, double b)
    {
        return(sqrt((a*a)+(b*b)));
    }
    
    printf(" %lf\n", py(3,3));
    return 0 ;
}
