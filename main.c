#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

extern void Lin2dBV(double out[], double in[], int n);

extern int divide(int dividend, int divisor);
extern bool isPowerOfTwo(int n);

extern double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size);

extern bool isPalindrome(int x);

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

    // find median
    //  int *nums1 = malloc(2*sizeof(int));
    //  int *nums2 = malloc(2*sizeof(int));
    int nums1Size, nums2Size;
    int nums1[] = {1, 5, 8, 3, 2};
    int nums2[] = {-1, 3, 4, 8, 5, 3, 1};
    nums1Size = 5;
    nums2Size = 7;
    double output;
    output = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("%f\n", output);

    int a = 1234567899;
    bool out;
    int hash_array[256] = {0};
    int *aa = malloc(2 * sizeof(int));
    for (int i = 0; i < 60; i++)
    {
        aa[i] = i;
    }
    out = isPalindrome(a);
    printf("%d\n", out);
    printf("int 类型的范围: %d 到 %d\n", INT_MIN, INT_MAX);
    printf("unsigned int 类型的最大值: %u\n", UINT_MAX);
    printf("short 类型的范围: %d 到 %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short 类型的最大值: %u\n", USHRT_MAX);
    printf("long 类型的范围: %ld 到 %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long 类型的最大值: %lu\n", ULONG_MAX);
    printf("long long 类型的范围: %lld 到 %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long 类型的最大值: %llu\n", ULLONG_MAX);

    return 0;
}