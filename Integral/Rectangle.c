/* Rectangle Method */
#include <stdio.h>
#include <math.h>
/*
 Defining equation to be solved.
 Change this equation to solve another problem.
*/
#define f(x) 1 / (1 + x * x) // f(x) = 1/(1+(x)^2)

// Rectangle method to calculate the integral
double rectangleMethod(double a, double b, int n)
{
    double h, sum, x;
    int i;
    h = (b - a) / n;
    x = 0;
    sum = 0.0;
    for (i = 0; i <= n - 1; i++)
    {
        x = a + i*h;
        sum = sum + (h * f(x)); // f(x_i) = 1/(1+(x_i)^2)
    }
    return sum;
}
