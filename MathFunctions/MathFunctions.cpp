
#include "MathFunctions.h"
#include <iostream>

using std::cout;
using std::endl;

double mysqrt(double A)
{
    cout << "This sqrt is come from customer function"<< endl;
    double x0 = A + 0.25, x1, xx = x0;
    for (;;)
    {
        x1 = (x0*x0 + A) / (2 * x0);
        if (fabs(x1 - x0) <= DBL_EPSILON) break;
        if (xx == x1) break;  //to break two value cycle.
        xx = x0;
        x0 = x1;
    }
    return x1;
}