#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

struct timeval  tv1, tv2;

int reverse (int x) {
    char str[100];
    memset(str, '\0', sizeof(char)*100);
    int i = 0;
    int negative = (x<0);
    if (negative) x = 0 -x; 
    while(1) {
        sprintf(&str[i], "%d", x%10);
        x = x/10;
        if (x == 0) break;
        i++;
    }
    if (negative) return 0 - atoi(str);
    return atoi(str);
}

int isPalindrome(int x) {
    int comp = x;
    if (x < 0) return 0;
    char str[32]; int i = 0;
    while(1) {
        sprintf(&str[i], "%d", x%10);
        x = x/10;
        if (x == 0) break;
        i++;
    }
    printf("ADIDBG %ld\n", atol(str));
    return ((comp - atol(str))==0);
}

int not_already_added (int *result, int count, int match)
{
    for (int i = 0; i < count; i++) {
        if (result[i] == match) return(0);
    }
    return(1);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *small, *big, siter, liter;
    if (nums1Size < nums2Size) {
        siter = nums1Size;
        liter = nums2Size;
        small = nums1;
        big = nums2;
    } else {
        siter = nums2Size;
        liter = nums1Size;
        small = nums2;
        big = nums1;
    }
    int count = 0, *result = malloc(sizeof(int)*siter);
    for (int i = 0; i < siter; i++) {
        int comp = small[i];
        for (int j = 0; j < liter; j++) {
            if (small[i] == big[j]) {
                /* check if we don't already have this in the result array */
                if (not_already_added(result, count, small[i])) {
                    result[count++] = small[i];
                }
            }
        }
    }
    *returnSize = count;
    return (result);
}

void find_max_cross (int *A, int start, int mid, int end, int *cross_start, int *cross_end, int *cross_sum)
{
    int sum_left = A[mid], sum_right = A[mid+1], sum = 0;
    int left = mid, right= mid+1, *res;
    for (int i = mid; i >= start; i--) {
        sum = sum + A[i];
        if (sum > sum_left) {
            sum_left = sum;
            left = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= end; i++) {
        sum = sum + A[i];
        if (sum > sum_right) {
            sum_right = sum;
            right = i;
        }
    }
    *cross_start = left;
    *cross_end = right;
    *cross_sum = sum_left + sum_right;
    return;
}

void find_max_subArray (int *A, int start, int end, int *left, int *right, int *sum)
{
    int mid, left_start, left_end, left_sum, right_start, right_end, right_sum;
    int cross_start, cross_end, cross_sum;
    if (start == end) {
        *left = start;
        *right = end;
        *sum = A[start];
        return;
    }
    mid = (start + end)/2;
    find_max_subArray(A, start, mid, &left_start, &left_end, &left_sum);
    find_max_subArray (A, mid+1, end, &right_start, &right_end, &right_sum);
    find_max_cross(A, start, mid, end, &cross_start, &cross_end, &cross_sum);
    if (left_sum >= right_sum && left_sum >= cross_sum) {
        *left = left_start;
        *right = left_end;
        *sum = left_sum;
        return;
    } else if (right_sum >= left_sum && right_sum >= cross_sum) {
        *left = right_start;
        *right = right_end;
        *sum = right_sum;
        return;
    }
    *left = cross_start;
    *right = cross_end;
    *sum = cross_sum;
}

int maxSubArray(int* nums, int numsSize) {
    int left, right, sum;
    find_max_subArray(nums, 0, numsSize-1, &left, &right, &sum);
    return sum;
}

double median_of_array (int *array, int len)
{
    if (len == 0) return (0);
    return array[len/2];
}
/*
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *A, *B, alen, blen;
    if (nums1Size < nums2Size) {
        A = nums1;
        B = nums2;
        alen = nums1Size;
        blen = nums2Size;
    } else {
        A = nums2;
        B = nums1;
        alen = nums2Size;
        blen = nums1Size;
    }
    if (alen == 0) return (median_of_array(B, blen));
    if (alen == 1) {
        // blen is also 1
        if (blen == 1) {
            return ((A[0] + B[0])/2);
        } 
        else if (blen%2) { // blen is odd
            return (-1);
        }
        // blen is even
        return (median_of_arrays_with_1_elem(B[blen/2], B[(blen/2)-1], A[0]));
    }
    if (alen == 2) {
        // blen is also 2

        // blen is odd

        // blen is even

    }
    

    // complete code before this line
    return (-1);
}
*/
short Parity1 (unsigned long x)
{
    short result = 0;
    
    gettimeofday(&tv1, NULL);
    while(x) {
        result = result ^ (x & 1);
        x >>= 1;
    }
    gettimeofday(&tv2, NULL);
    printf("Took %f sec to execute\n", (double) ((tv2.tv_usec - tv1.tv_usec) / 1000000) +
         (double) (tv2.tv_sec - tv1.tv_sec));
    return result;
}

short Parity2 (unsigned long x)
{
    short result = x;

    while(x) {
        result = result ^ (x & 1);
        x &= (x-1);
    }
    return result;
}

int main ()
{   
    int num;
    //scanf("%d", &num);
    //printf("Reverse of %d is %d\n", num, reverse(num));
    //printf("%d %s palindrome\n", num, isPalindrome(num) ? "is":"is not");
    int arr1[] = {1,2,3,4,5,6};
    int arr2[] = {2,2,5,6};
    int result_count;
    int *result = NULL;
    //printf("array %s non decreasing\n", checkPossibility(arr, 6)? "is": "is not");
    result = intersection(arr1, 6, arr2, 4, &result_count);
    for (int i = 0; i < result_count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    int arr3[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("Size of arr3 is %ld\n", sizeof(arr3)/sizeof(arr3[0]));
    printf("Max sub-array size is %d\n", maxSubArray(arr3, sizeof(arr3)/sizeof(arr3[0])));
    printf("Parity of 364768825361 is %d\n", Parity1(364768825361));

    return (0);
}