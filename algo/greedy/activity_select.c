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
    //todo
}

int main() {
    /* 1. Minimum product subset of an array */
    int arr[] = {-1, 1, 2, -4, 3};
    printf("MinPS is %d\n", minimum_product_subset(arr, 5));
    printf("MaxPS is %d\n", maximum_product_subset(arr, 5));

	return 0;
}