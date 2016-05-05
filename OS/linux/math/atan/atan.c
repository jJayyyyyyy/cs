#include <stdio.h>
#include <math.h>
#include "atan.h"

// print arctan(a/b)
void arctan(double a, double b)
{
    double alpha = atan(a/b);

    printf("%g\n", alpha);
    printf("%f degrees\n", alpha*180.0/3.14159265);
}
