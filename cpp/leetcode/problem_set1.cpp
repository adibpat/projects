#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution1_bf {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution(2,0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if(nums[i]+nums[j]==target) {
                    solution[0]=i;
                    solution[1]=j;
                    return(solution);
                }
            }
        }
        return solution;
    }
};

class Solution1_hm {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution(2,0);
        multimap<int, int> compliment;
        for (int i = 0; i < nums.size(); ++i) {
            multimap<int, int>::iterator iter = compliment.find(target-nums[i]);
            if (iter != compliment.end()) {
                solution[0] = iter->second;
                solution[1] = i;
                return solution;
            }
            compliment.insert(pair<int,int>(nums[i], i));
        }
        return solution;
    }
};

class Solution_3 {
public:
    void find_next_smallest_num(vector<int>&x) {
        vector<int>::reverse_iterator first_asc = x.rbegin(), max_lt_fa = x.rbegin();
        vector<int>::reverse_iterator swap_iter, riter;
        int max, min;
        /* Find first instance of ascending order */
        while(first_asc != x.rend()) {
            if (*first_asc < *(first_asc+1)) {
                cout<<"Found "<<*first_asc<<" less that "<<*(first_asc+1)<<endl;
                ++first_asc;
                break;
            }
            first_asc++;
        }
        cout<<"Find latgest number smaller than "<<*first_asc<<" in right portion"<<endl;
        max = 0;
        /* Find the max less that first_asc to swap */
        while (max_lt_fa != first_asc) {
            if(*max_lt_fa > max && *max_lt_fa < *first_asc) {
                max = *max_lt_fa;
                swap_iter = max_lt_fa;
            }
            max_lt_fa++;
        }
        cout<<"Found "<<max<<" to be swapped with "<<*first_asc<<endl;
        *swap_iter = *first_asc;
        *first_asc = max;
        cout<<"Now sort rest in descending order"<<endl;
        for (max_lt_fa = x.rbegin(); max_lt_fa < first_asc ; ++max_lt_fa) {
            min = *max_lt_fa;
            for (riter = max_lt_fa+1; riter != first_asc; ++riter) {
                if (*riter < min) {
                    min = *riter;
                    swap_iter = riter;
                }
            }
            cout<<"Found min "<<min<<" to swap with "<<*max_lt_fa<<endl;
            if (min == *max_lt_fa) break;
            *swap_iter = *max_lt_fa;
            *max_lt_fa = min;
        }
    }

};

int main() {
    // Solution1_hm x;
    // int arr[] = {3,3};
    // vector<int> a(arr, arr + sizeof(arr)/sizeof(arr[0])); 
    // vector<int> solution = x.twoSum(a,6);
    // //solution = x.twoSum(a,12);
    
    // cout<<solution[0]<<" "<<solution[1]<<endl;

    // string s = "Aditya will be a good husband";

    // string ss = s.substr(5);

    // cout<<ss;

    Solution_3 x;
    vector<int> y;
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    y.push_back(4);
    y.push_back(5);
    y.push_back(5);    
    y.push_back(4);
    y.push_back(3);
    y.push_back(2);
    y.push_back(1);

    x.find_next_smallest_num(y);
    vector<int>::iterator iter = y.begin();
    for (; iter != y.end(); ++iter) {
        cout<<*iter<<" ";
    }
    return(0);
}
