#include <stdio.h>
#include <math.h>

int main()
{
    double a,b;
    double alpha;

    a = 1.0;
    b = 2.0;
    alpha = asin(a/b);
    printf("%g\n", alpha);
    printf("%f degrees\n", alpha*180.0/3.1415927);
}
