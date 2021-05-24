#include <stdio.h>
#include <math.h>

// Euler function
void Euler(FILE *euler, char *name,double x0, double y0, double T, int n)
{
    double h, diff1, diff2;
    h = 2 * T / n;
    euler = fopen(name, "w");
    for (int i = 0; i < n; i++)
    {

        diff1 = y0;
        diff2 = -sin(x0);
        //printf("x%d = %0.4lf\tx%d = %lf\n", i, x0, i, y0);
        fprintf(euler, "%lf\t%lf\t%lf\n", x0, y0,x0+y0);
        y0 = y0 + h * diff2;
        x0 = x0 + h * diff1;
    }
    fclose(euler);
}

