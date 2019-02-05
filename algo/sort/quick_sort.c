#include <stdio.h>
#include <stdlib.h>
#include "my_sort.h"

void swap (int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high ; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quick_sort (int *arr, int low, int high)
{
    //printf("Low %d, High %d\n", low, high);
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot-1);
        quick_sort(arr, pivot+1, high);
    }
}

void quick_sort_driver (int arr_size, int *arr)
{
    //printf("Driver program called\n");
    quick_sort (arr, 0, arr_size-1);
}
