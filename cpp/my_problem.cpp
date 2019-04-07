# include<iostream>
#include <vector>

using namespace std;


int gcd (int a, int b)
{
    if (a==b) return (a);
    if (a>b) return (gcd(a-b,b));
    return (gcd(b-a,a));
}

void swap( int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
    
class rotate_array {    
    int find_pivot (vector<int> &a) {
        int l = 0, h = a.size()-1;
        int mid;

        while(1) {
            mid = (l+h)/2;
            if (a[mid] > a[mid+1]) {
                return mid;
            } else if (a[mid] < a[l]) {
                h = mid;
            } else if (a[mid] > a[h]) {
                l = mid;
            } else {
                break;
            }
        }
        return (a.size()-1);
    }
public:
    int search (vector<int> &a, int l, int h, int target)
    {
        if (h < l) return (-1);
        int mid = (l+h)/2;
        if (a[mid] == target) {
            return (mid);
        } else if (a[l] < a[mid]) {
            if (a[l] <= target && a[mid] > target) {
                return search(a, l, mid-1, target);
            } else {
                return search(a, mid+1, h, target);
            }
        } else if (a[mid] < a[h]) {
            if (a[mid] < target && a[h] >= target) {
                return search(a, mid+1, h, target);
            } else {
                return search(a, l, mid-1, target);
            }
        } else {
            if (a[l] == a[mid] && a[mid] != a[h]) {
                return search(a, mid+1, h, target);
            }
            int t1 = search(a, l, mid-1, target);
            int t2 = search(a, mid+1, h, target);
            if (t1 >= 0 || t2 >= 0) return (1);
            return (-1);
        }
        return (-1);
    }
    bool sum (vector<int> &a, int target) {
        int pivot = find_pivot(a);
        int l = pivot+1, h = pivot, numsize = a.size();
        while(l!=h) {
            if (l > numsize) l = l-numsize;
            if (h<0) h = h+numsize;
            if (a[l] + a[h] == target) {
                return (1);
            } else if (a[l] + a[h] < target) {
                l++;
            } else {
                h--;
            }
        }
        return (0);
    }
    void split_and_add_back (vector<int> &a, int k) // juggling algo
    {
        int sets = gcd(a.size(), k);
        cout << "GCD of " << a.size() << " and " << k << " is " << sets << endl;
        for (int i = 0; i < sets; i++) {
            int j = i, temp = a[j];
            for (; ;) {
                int d = j + k;
                if (d > a.size()-1) { d = d - a.size(); }
                if (d == i) break;
                a[j] = a[d];
                j = d;
            }
            a[j] = temp;
        }
    }
    void split_and_add_back (vector<int> &a, int k, int i) // reversal algo
    {
        cout << "Using reversal algo" << endl;
        for (int i = 0, j = a.size()-1; j >= i; i++, j--) {
            swap(&a[i], &a[j]);
        }
        //this->print_array(a);
        for (int i = 0, j = a.size()-1-k; j >= i; i++, j--) {
            swap(&a[i], &a[j]);
        }
        for (int i = a.size()-k, j = a.size()-1; j >= i; i++, j--) {
            swap(&a[i], &a[j]);
        }
        
    }
};

class rearrange {
public:
    
    void index_as_value_at_index (vector<int> &a)
    {
        int arr_size = a.size();
        sort(a.begin(), a.end());
        for (int i = 0, j = 0; i < arr_size && j < arr_size; ) {
            if (a[j] == i) {
                a[i] = i;
                i++; j++;
            }
            if (a[j] > i) {
                a[i] = -1;
                i++;
            }
            if (a[j] < i) {
                j++;
            }
        }
    }
    void index_as_value_at_index (vector<int> &a, int k)
    {
        int i = 0;
        while (i < a.size()) {
            if (a[i] != -1 && a[i] != i) {
                a[a[i]] = a[i];
                a[i] = -1;
            }
            i++;
        }
    }
    void larger_even_smaller_odd (vector<int> &a)
    {
        vector<int> arr = a;
        sort(arr.begin(), arr.end());
        //print_array(arr);
        int even_index = a.size() - a.size()/2;

        for (int i = 1; i < arr.size(); i+=2) {
            a[i] = arr[even_index++];
        }

        int odd_index = a.size() - a.size()/2 - 1;
        for (int i = 0; i < arr.size(); i+=2) {
            a[i] = arr[odd_index--];
        }
        return;
    }
    void alternate_pos_neg (vector<int> &a)
    {
        int j = -1;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] >= 0) {
                swap(&a[++j], &a[i]);
            }
        }
        int pivot = j;
        cout << "After modified partition" << endl;
        print_array(a);
        for (int i = 1, j = a.size()-1; i <= pivot ; i+=2, j--) {
            swap(&a[i], &a[j]);
        }
        return;
    }
    void alternate_pos_neg (vector<int> &a, int k)
    {
        for (int i = 0; i < a.size(); i++) {
            if (i%2 == 0 && a[i] >= 0) {
                // element misplaced
                int j;
                for (j = i+1; j < a.size() && a[j] >=0; j++);
                if (j >=  a.size()) break;
                int temp = a[j];
                while(j!=i) {
                    a[j] = a[j-1];
                    j--;
                }
                a[j] = temp;
            } else if (i%2 && a[i] < 0) {
                int j;
                for (j = i+1; j < a.size() && a[j] < 0; j++);
                int temp = a[j];
                while (j!=i) {
                    a[j] = a[j-1];
                    j--;
                }
                a[j] = temp;
            }
        }
        return;
    }
    void move_zeros_to_end (vector<int> &a)
    {
        int zero_iter = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != 0) {
                swap(&a[i], &a[++zero_iter]);
            }
        }
        return;
    }
    int swaps_to_bring_elems_together (vector<int> &a, int k)
    {
        /* Find number of elements to chunk together */
        int chunk = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] <= k) chunk++;
        }
        /* Establish baseline in the first window */
        int greater = 0;
        for (int i = 0; i < chunk; i++) {
            if (a[i] > k) greater++;
        }
        int min_swaps = greater;
        /* Now move the sliding windown to find the min value of greater */
        for (int i = 1, j = i + chunk; j < a.size(); i++, j++) {
            if (a[i-i] <= k) greater--;
            if (a[j] <= k) greater++;
            if (min_swaps < greater) min_swaps = greater;
        }
        return (min_swaps);
    }
};

int main ()
{
    int arr_help[] = {4,5,6,8,9,10};
    vector<int> arr (arr_help, arr_help + sizeof(arr_help)/sizeof(int));
    rotate_array r;
    //cout << r.search(arr, 0, arr.size()-1, 3);
    /*
    cout << "Sum found ";
    if (r.sum(arr, 16)) {
    cout << "Yes" << endl;
    } else {
    cout << "No" << endl;
    }
    */
    r.split_and_add_back(arr, 2,1);
    print_array(arr);

    cout << "Rearrangement problems begin " << endl;
    rearrange re;
    int arr_help1[] = {1,9,8,4,0,0,2,7,0,6,0};
    vector<int> arr1(arr_help1, arr_help1 + sizeof(arr_help1)/sizeof(int));
    //re.index_as_value_at_index(arr1, 1);
    //re.larger_even_smaller_odd (arr1);
    //re.alternate_pos_neg(arr1,1);
    re.move_zeros_to_end(arr1);
    print_array(arr1);
    return (0);
}
