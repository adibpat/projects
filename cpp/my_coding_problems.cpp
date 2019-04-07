#include <iostream>
#include <vector>
#include <array>

using namespace std;

int gcd (int a, int b) 
{
    if (a == b) return (a);
    if (a > b) return (gcd(a-b,b));
    return (gcd(b-a,a));
}

class Solution {
private:
    int bst_with_mid (vector<int>& nums, int pivot, int target)
    {
        int l, h, mid;
        if (target < nums[0]) {
            l = pivot + 1;
            h = nums.size() - 1;
        } else {
            l = 0;
            h = pivot;
        }
        while (h>=l) {
            mid = (l+h)/2;
            if (target == nums[mid]) {
                return (mid);
            } else if (target < nums[mid]) {
                h = mid;
            } else if (target > nums[mid]) {
                l = mid;
            } else return(-1);
        }
        return (-1);
    }
public:
    void rotate(vector<int>& nums, int k)
    {
        int nums_size = nums.size();
        int step = gcd(nums_size, k);
        for (int i = 0; i < step; ++i) {
            int j = nums_size - 1 - i;
            int temp = nums[j];
            while (1) {
                int d = j - k;
                if (d < 0) d = d + nums_size;
                if (d == nums_size - 1 - i) break;
                nums[j] = nums[d];
                j = d;
            }
            nums[j] = temp;
        }
    }
    int rotated_array_bs(vector<int>& nums, int target)
    {
        int mid = nums.size()/2, l = 0, h = nums.size()-1;
        while(mid!=l || mid!=h) {
            if (nums[mid] < nums[l]) {
                // pivot lies in left sub-part
                h = mid;
                mid = (l + h)/2;
            } else if (nums[mid] > nums[h]) {
                // pivot lies in right sub-part
                l = mid;
                mid = (l + h)/2;
            }
            if (nums[mid] > nums[mid+1]) break;
        }
        cout << "Pivot element " << nums[mid] <<" found at " << mid << endl; 
        int pivot = mid;
        return(bst_with_mid(nums, mid, target));
    }
};

int main ()
{
    Solution s;
    int arr_helper[] = {1,1};
    vector<int> arr(arr_helper, arr_helper + sizeof(arr_helper)/sizeof(int));
    //s.rotate(arr, 3);
    for (int iter = 0; iter < arr.size(); iter++)
    {
        cout << iter << " ==> " << arr[iter] << endl;
    }
    cout << "Found 0 at location " << s.rotated_array_bs(arr, 5) << endl;
    
    return (0);
}
