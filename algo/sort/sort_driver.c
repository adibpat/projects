#include <stdio.h>
#include <stdlib.h>
#include "my_sort.h"

int main (int argc, char *argv[])
{
    int arr[] = {5,7,4,2,1,3,6};
    quick_sort_driver(7, arr);
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
