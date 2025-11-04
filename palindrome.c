#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

bool isPalindrome(int x);
char* longestPalindrome(char* s);

int main()
{
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

bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }
    long long reverse_num = 0;
    int init_num = x;
    int hash_array[256] = {0};
    while (x > 0)
    {
        int low_int = x % 10;
        reverse_num = reverse_num * 10 + low_int;
        x = x / 10;
    }
    return init_num == reverse_num;
}

/*char* longestPalindrome(char* s){
    int len = strlen(s);
    int hash_array[256] = {0};
    int tmp = 0;
    int out_cnt, cnt = 0;
    for (int i = 0; i < len; i++){
        if (hash_array[s[i]] != 0){
            out_cnt = cnt;
        }else{
            hash_array[s[i]] = cnt + 1;
        }
        while(hash_array[s[i]] == 0){

        }
    }

}*/