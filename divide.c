#include <limits.h>
#include <stdbool.h>

int divide(int dividend, int divisor);
bool isPowerOfTwo(int n);

void main()
{

    int dividend = 10;
    int divisor = 3;
    int quo = divide(dividend, divisor);
    printf("quo is %d\n", quo);

    int n = 1;
    bool is = isPowerOfTwo(n);
    printf("n is %d\n", is);
}

int divide(int dividend, int divisor)
{

    int out = 0;
    bool neg_flag;

    if (dividend == 0)
    {
        return 0;
    }

    if (dividend == INT_MIN)
    {
        if (divisor == 1)
        {
            return INT_MIN;
        }
        if (divisor == -1)
        {
            return INT_MAX;
        }
    }

    if (divisor == 1)
    {
        return dividend;
    }
    else if (divisor == -1)
    {
        return -dividend;
    }

    if (divisor == INT_MIN)
    {
        return dividend == INT_MIN ? 1 : 0;
    }

    if ((divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0))
        neg_flag = false;
    else
        neg_flag = true;

    if (dividend > 0)
        dividend = -dividend;

    if (divisor > 0)
        divisor = -divisor;

    if (dividend == divisor)
    {
        if (neg_flag == 0)
            return 1;
        else
            return -1;
    }

    if (dividend > divisor)
    {
        return 0;
    }

    int tmp = 0;
    int cnt = 1;
    int res = 0;

    while (divisor >= dividend)
    {
        tmp += divisor;
        dividend -= tmp;
        res += cnt;
        cnt++;
    }

    if (dividend > 0)
    {
        dividend += tmp;
        res = res - cnt + 1;
        while (dividend <= divisor)
        {
            dividend -= divisor;
            res++;
        }
    }

    if (neg_flag)
        out = -res;
    else
        out = res;

    return out;
}

bool isPowerOfTwo(int n)
{
    int max_int = 31;
    int min_int = -31;
    int mid_int = 0;
    int new_int = 0;
    if (n > 0)
    {
        n = -n;
    }
    for (int i = 1; i < 32; i++)
    {
        if (n == 1 << min_int)
            return true;
        else
        {
            if (n > (1 >> min_int))
            {
                max_int = mid_int;
                new_int = (max_int + min_int) / 2;
                min_int = new_int;
            }
        }
    }
}