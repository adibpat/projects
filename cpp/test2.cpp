#include <iostream>
#include <vector>
#include <stddef.h>
#include <string>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

typedef enum {
    black,
    white,
    red
} COLOR;

int main (void) {

    vector<int> A; 
    A.push_back(0);
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    vector<COLOR> color;
    color.resize(A.size());

    for (size_t i = 0; i < A.size(); i++) {
        color[i] = static_cast<COLOR>(A[i]);
    }
    vector<int>* c_ptr = &A;
    for (int i = 0; i < c_ptr->size(); ++i) {
        cout << c_ptr[i] << ' ';
    }
    cout << endl;
    return (0);
}