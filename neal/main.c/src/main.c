#include <kipr/wombat.h>
#include<math.h>

int main()
{
    double quadraticpos(double a, double b, double c)
    {
        return(((-1*b)+sqrt((b*b)-(4*a*c))/(2*a)));
    }
    double quadraticmin(double a, double b, double c)
    {                 
        return(((-1*b)-sqrt((b*b)-(4*a*c))/(2*a)));
    }
    printf("%lf",quadraticpos(1,2,2));
    return 0;
}
