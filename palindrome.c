#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

bool isPalindrome(int x);
char *longestPalindrome(char *s);

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