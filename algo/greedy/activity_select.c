#include <stdio.h>
#include <stdlib.h>

void select_activity(int arr_size, int *start_arr, int *finish_arr)
{
    // todo
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
	    int arr_size, *start_arr = NULL,*finish_arr = NULL;
	    scanf("%d", &arr_size);
	    start_arr = malloc(sizeof(int)*arr_size);
	    finish_arr = malloc(sizeof(int)*arr_size);
        for (int j = 0; j < arr_size; j++) {
            scanf("%d ", &start_arr[j]);
        }
        for (int j = 0; j < arr_size; j++) {
            scanf("%d ", &finish_arr[j]);
        }
        select_activity(arr_size, start_arr, finish_arr);
	}
	return 0;
}