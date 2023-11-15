#include <stdio.h>
#include <math.h>

float f(float x) 
{
    return pow(x, 4) - x - 9;
}

float df(float x)
{
    return 4 * pow(x, 3) - 1;
}

int main() 
{
    int itr, maxitr;
    float h, x0, x1, aerr;

    printf("Enter x0, allowed error, maximum iterations\n");
    scanf("%f%f%d", &x0, &aerr, &maxitr);

    for (itr = 1; itr <= maxitr; itr++) 
    {
        h = f(x0) / df(x0);
        x1 = x0 - h;
        printf("Iteration number %d, x = %f \n", itr, x1);

        if (fabs(h) < aerr) 
        {
            printf("After %d iterations, root = %f \n", itr, x1);
            return 0;
        }

        x0 = x1;
    }

    printf("Iterations not sufficient, solution does not converge\n");
    return 1;

/*Credits: Chayashree*/
