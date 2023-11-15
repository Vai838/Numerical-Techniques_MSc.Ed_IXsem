#include <stdio.h>

// Function to perform Newton's Forward Interpolation
double newtonsForwardInterpolation(double x, int n, double x_values[], double y_values[]) {
    double result = 0.0;

    // Calculate the first differences
    double h = x_values[1] - x_values[0];

    // Construct the forward difference table
    double forward_difference[n][n];
    for (int i = 0; i < n; i++) {
        forward_difference[i][0] = y_values[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            forward_difference[i][j] = forward_difference[i + 1][j - 1] - forward_difference[i][j - 1];
        }
    }

    // Compute the interpolating polynomial
    result = forward_difference[0][0];
    double u = (x - x_values[0]) / h;

    for (int i = 1; i < n; i++) {
        result += (u / i) * forward_difference[0][i];
        u *= (u - 1);
    }

    return result;
}

int main() {
    int n;

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x_values[n];
    double y_values[n];

    // Input the data points
    printf("Enter the x-values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x_values[i]);
    }

    printf("Enter the y-values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y_values[i]);
    }

    double x;

    // Input the point at which to estimate the value
    printf("Enter the value of x for interpolation: ");
    scanf("%lf", &x);

    // Perform Newton's Forward Interpolation
    double result = newtonsForwardInterpolation(x, n, x_values, y_values);

    // Output the estimated value
    printf("Estimated value at x = %.2lf: %.4lf\n", x, result);

    return 0;
}

/*Credits to Mohammed Bin Shakir and ChatGPT*/
