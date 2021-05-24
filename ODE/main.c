#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Euler.h"

// convert int to string
void tostring(char str[], int num)
{
    int i, rem, len = 0, n;

    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

// The main contains the generation of the name of .txt file and the plot of multiple files
int main()
{
    double value = 6 * M_PI, val = value, val1 = value, k = -2.0, k1 = -0.5, k2 = 2.0;

    int v = 1;

    for (int i = 1; i <= 51; i++)
    {
        char number[12];
        FILE *euler = NULL;

        tostring(number, i);
        strcat(number, ".txt");
        char nameFile[] = "Euler\0";
        strcat(nameFile, number);

        if (i % 8 != 1 && i % 8 != 2 && i % 8 != 3)
        {
            if (i <= 16)
            {
                Euler(euler, nameFile, 0.0, k, val, 1000);
                k = k - 0.5;
                if ((i >= 8))
                    val = -value;
                if (i == 8)
                    k = -2;
            }
            if (i >= 20)
            {
                Euler(euler, nameFile, 0.0, k2, -val, 1000);
                k2 = k2 + 0.5;
                if (i >= 24)
                    val = value;
                if (i == 24 || i==32 || i==40)
                    k2 = 2;


            }
        }
        if ((i % 8 == 1 || i % 8 == 2 || i % 8 == 3))
        {
            Euler(euler, nameFile, val1, k1, value, 10000);
            k1 = k1 - 0.5;
            v++;
            if (v > 3)
            {
                v = 1;
                k1 = -0.5;
                val1 -= 2 * M_PI;
            }
        }
    }
    // plot multiple file in the same graph at a specific interval of x
    system("gnuplot -p -e \" plot [-18.8496:18.8496] 'Euler1.txt'  w l title '', 'Euler2.txt'  w l title '','Euler3.txt'  w l title '', 'Euler4.txt'  w l title '' , 'Euler5.txt'  w l title '','Euler6.txt'  w l title '','Euler7.txt'  w l title '', 'Euler8.txt'  w l title '' , 'Euler9.txt'  w l title '','Euler10.txt'  w l title '', 'Euler11.txt' w l title '', 'Euler12.txt' w l title '','Euler13.txt'  w l title '', 'Euler14.txt'  w l title '' , 'Euler15.txt'  w l title '','Euler16.txt'  w l title '','Euler17.txt'  w l title '', 'Euler18.txt'  w l title '', 'Euler19.txt'  w l title '', 'Euler20.txt' w l title '', 'Euler21.txt' w l title '', 'Euler22.txt' w l title '','Euler23.txt'  w l title '', 'Euler24.txt'  w l title '' , 'Euler25.txt'  w l title '','Euler26.txt'  w l title '','Euler27.txt'  w l title '', 'Euler28.txt'  w l title '', 'Euler29.txt' w l title '', 'Euler30.txt' w l title '', 'Euler31.txt' w l title '', 'Euler32.txt' w l title '', 'Euler33.txt' w l title '', 'Euler34.txt' w l title '', 'Euler35.txt' w l title '', 'Euler36.txt' w l title '', 'Euler37.txt' w l title '', 'Euler38.txt' w l title '', 'Euler39.txt' w l title '', 'Euler40.txt' w l title '', 'Euler41.txt' w l title '', 'Euler42.txt' w l title '', 'Euler43.txt' w l title '', 'Euler44.txt' w l title '', 'Euler45.txt' w l title '', 'Euler46.txt' w l title '', 'Euler47.txt' w l title '', 'Euler48.txt' w l title '', 'Euler49.txt' w l title '', 'Euler50.txt' w l title '', 'Euler51.txt' w l title ''\"");
    return 0;
}
