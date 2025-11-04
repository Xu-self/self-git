#include <stdio.h>
#include <stdbool.h>

extern void Lin2dBV(double out[], double in[], int n);

int main()
{
    // lin2db
    double value[3];
    double input[3] = {32, 2, 3};
    Lin2dBV(value, input, 3);
    for (int i = 0; i < 3; i++)
    {
        printf("%f\t", value[i]);
    }

    // divide
    int dividend = 10;
    int divisor = 3;
    int quo = divide(dividend, divisor);
    printf("quo is %d\n", quo);

    int n = 1;
    bool is = isPowerOfTwo(n);
    printf("n is %d\n", is);
    return 1;
}