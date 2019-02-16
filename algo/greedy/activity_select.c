#include <stdio.h>
#include <stdlib.h>
#include "../sort/my_sort.h"

void select_activity(int arr_size, int *start_arr, int *finish_arr)
{
    // todo
}

int minimum_product_subset (int *arr, int arr_size)
{
    int negative = 0, product = 1, max_neg = 0;
    quick_sort_driver(arr_size, arr);
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] < 0) {
            negative++;
            max_neg = (arr[i] < max_neg) ? arr[i] : max_neg;
        }
        if (arr[i] == 0) return (0);
    }
    if (negative%2) {
        for (int i = 0; i < arr_size; i++) {
            product *= arr[i];
        }
        return (product);
    } else if (negative > 0) {
        for (int i = 0; i < arr_size; i++) {
            product *= arr[i];
        }
        return (product/max_neg);
    }
    return (arr[0]);
}

int maximum_product_subset (int *arr, int arr_size)
{
    int negative = 0, zeros = 0, product = 1, max_neg = arr[0];
    quick_sort_driver(arr_size, arr);
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] < 0) {
            negative++;
            if (max_neg < arr[i]) max_neg = arr[i];
        }
        if (arr[i] != 0) product *= arr[i];
    }
    if (negative%2) 
        return (product/max_neg);
    return (product);
}

int maximum_sum_k_negations(int *arr, int arr_size, int k)
{
    int sum = 0;
    int i = 0;
    quick_sort_driver(arr_size, arr);
    while(1) {
        if (arr[i] > 0) break;
        if (k) {
            sum = sum - arr[i];
            k--;
        }
        i++;
    }
    for (int j = i; j < arr_size; j++) {
        sum += arr[j];
    }
    return (sum);
}

int main() {
    /* 1. Minimum product subset of an array */
    int arr1[] = {-1, -1, -2, 4, 3};
    printf("MinPS is %d\n", minimum_product_subset(arr1, 5));
    printf("MaxPS is %d\n", maximum_product_subset(arr1, 5));
    int arr2[] = {-2, 0, 5, -1, 2};
    printf("MaxSKN is %d\n", maximum_sum_k_negations(arr1, 5, 1));

	return 0;
}