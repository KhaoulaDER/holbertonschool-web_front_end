/* Simpson Method */
#include <stdio.h>
#include <math.h>
/*
 Defining equation to be solved.
 Change this equation to solve another problem.
*/
#define f(x) 1 / (1 + x * x) // f(x) = 1/(1+(x)^2)

// Simpson method to calculate the integral
double simpson(double a, double b, int n)
{
    double x, h, sum, SIntegral;
    int i;

    // Calculate h
    h = fabs(b - a) / n;
    x = a;

    sum = 0;



    for(i=1;i<n;i++){
    x=a+i*h;
    if(i%2==0){
      sum=sum+2*f(x);
    }
    else{
      sum=sum+4*f(x);
    }
  }
  SIntegral=(h/3)*(f(a)+f(b)+sum);
    // Calculate the integral
    return (SIntegral);

}
