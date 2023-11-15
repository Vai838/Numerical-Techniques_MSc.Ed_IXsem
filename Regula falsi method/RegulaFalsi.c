#include <stdio.h>
#include <math.h>

// Define the function f(x)
double f(double x) {
    return x * x * x - 2 * x * x + x - 1;
}

// False Position Method
double false_position(double a, double b, double tol, int max_iter) {
    double c, fc, fa, fb;
    int iter = 0;

    do {
        fa = f(a);
        fb = f(b);
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);

        if (fa * fc < 0) {
            b = c;
        } else {
            a = c;
        }

        iter++;

        if (fabs(fc) < tol || iter >= max_iter) {
            break;
        }
    } while (1);

    return c;
}

int main() {
    double a, b, tol, root;
    int max_iter;

    printf("Enter interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter tolerance: ");
    scanf("%lf", &tol);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iter);

    if (f(a) * f(b) >= 0) {
        printf("The false position method may not converge on the given interval.\n");
    } else {
        root = false_position(a, b, tol, max_iter);
        printf("Approximate root: %.8f\n", root);
    }

    return 0;
}

/*Credits: Anil*/
