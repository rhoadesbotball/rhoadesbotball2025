#include <kipr/wombat.h>
#include<math.h>

int main()
{
    double quadraticpos(int a, int b, int c)
    {
        return(((-1*b)+sqrt((b*b)-(4*a*c))/(2*a)));
    }
    
    printf("%lf",quadraticpos(1,2,2));
    return 0;
}
