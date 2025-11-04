#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void QuickSort(int *arr, int begin, int end);
void Buttersort(int *arr, int len);
void Shellsort(int *arr, int len);

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int len = nums1Size + nums2Size;
    int *new_array = malloc(len * sizeof(int));
    int tmp = 0;
    double out = 0;
    for (int i = 0; i < nums1Size; i++)
    {
        new_array[i] = nums1[i];
    }
    for (int i = 0; i < nums2Size; i++)
    {
        new_array[i + nums1Size] = nums2[i];
    }
    // Buttersort(new_array, len);
    // Shellsort(new_array, len);
    QuickSort(new_array, 0, 11);
    for (int i = 0; i < len; i++)
    {
        double tmp_out = new_array[i];
        printf("%f\t", tmp_out);
    }
    if (len % 2 == 1)
        out = new_array[len / 2];
    else
        out = (new_array[len / 2] + new_array[len / 2 - 1]) / 2.;
    return out;
}

void Buttersort(int *arr, int len)
{
    while (len)
    {
        int tmp = 0;
        int flag = 0;
        for (int i = 1; i < len; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                tmp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = tmp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
        len--;
    }
}

void Shellsort(int *arr, int len)
{
    int gap = len;
    int end, tmp;
    while (gap > 1)
    {
        gap = gap / 2;
        for (int i = 0; i < len - gap; i++)
        {
            end = i;
            tmp = arr[end + gap];
            while (end >= 0)
            {
                if (tmp < arr[end])
                {
                    arr[end + gap] = arr[end];
                    end = end - gap;
                }
                else
                {
                    break;
                }
            }
            arr[end + gap] = tmp;
        }
    }
}
// hoare
void QuickSort(int *arr, int begin, int end)
{
    int tmp;
    // 只有一个数或区间不存在
    if (begin >= end)
        return;
    int left = begin;
    int right = end;
    // 选左边为key
    int keyi = begin;
    while (begin < end)
    {
        // 右边选小   等号防止和key值相等    防止顺序begin和end越界
        while (arr[end] >= arr[keyi] && begin < end)
        {
            --end;
        }
        // 左边选大
        while (arr[begin] <= arr[keyi] && begin < end)
        {
            ++begin;
        }
        // 小的换到右边，大的换到左边
        tmp = arr[end];
        arr[end] = arr[begin];
        arr[begin] = tmp;
    }
    tmp = arr[end];
    arr[end] = arr[keyi];
    arr[keyi] = tmp;
    keyi = end;
    //[left,keyi-1]keyi[keyi+1,right]
    QuickSort(arr, left, keyi - 1);
    QuickSort(arr, keyi + 1, right);
}
