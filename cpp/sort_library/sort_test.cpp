#include <iostream>
#include "sort_lib.h"
#include <vector>


/*
 * This is a test file for testing sorting algorithms on
 * arrays 
 * 
 * 1. Insertion Sort
 * 2. Selection Sort
 * 3. Merge Sort
 * 4. Quick Sort
 * 5. Heap Sort
 *
 */

int main() {

    std::cout<< "Entered main" << std::endl;
    std::vector<int> nums = {7,6,5,4,3,2,1};
    sortLib::MySortLib::quickSort(nums);
    return (0);
}
