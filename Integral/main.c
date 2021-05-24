#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Rectangle.h"
#include "Simpson.h"

void Error(FILE *name1, FILE *name2, int n, int number, double a, double b)
{
    name1 = fopen("Error_Rectangle_Method.txt", "w");
    name2 = fopen("Error_Simpson_Method.txt", "w");
    int iteration = 0;
    while (iteration < number)
    {
        //double error2 = log(fabs(simpson(a, b, n) - M_PI / 4));
        //double error1 = log(fabs(rectangleMethod(a, b, n) - M_PI / 4));
        fprintf(name2, "%d\t%lf\n", n, log10(fabs(simpson(a, b, n) - M_PI / 4)));
        fprintf(name1, "%d\t%lf\n", n, log10(fabs(rectangleMethod(a, b, n) - M_PI / 4)));



        n = n + 100;
        iteration++;
    }
    fclose(name1);
    fclose(name2);

    system("gnuplot -p -e \"plot 'Error_Rectangle_Method.txt'  w l, 'Error_Simpson_Method.txt' w l \"");

}
int main()
{

    double a, b;
    int n, number;
    // Initialize input values
    a = 0.0;
    b = 1.0;
    FILE *error1 = NULL, *error2 = NULL;
    printf("Enter the number of divisions n: ");
    scanf("%d", &n);
    printf("Enter the number of iterations: ");
    scanf("%d", &number);
    Error(error1, error2, n, number, a, b);
    //printf("The approximate integral value with simpson method is: %lf \n", simpson(a, b, n));
    return 0;
}
