#include <iostream>
#include <vector>
    
/************************************
 * Some Experimentation with vectors*
 ************************************/
    
using namespace std;

int main (int argc, char **argv) {

    vector<int> v;
    vector<int> *v_ptr = &v;

    v.push_back(11);
    v.push_back(22);

    cout << "Size of v is " << v.size() << endl; /* Answer is 2 */

    v_ptr->push_back(33);
    v.push_back(44);

    cout << "Size of v is " << v_ptr->size() << endl; /* Answer is 4 */

    v[5] = 55; /* This is wrong because this vector does not have a 5th element yet. 
                  but it works */

    for (size_t i = 0; i < v.size(); i++) cout << v[i] << " "; /* Vector knows its own size */
    cout << endl;

    cout << "Trying to access 10th element: " << v[10] << endl; /* This shows 0, don't know what is going on */

    vector<int>::iterator i = v.begin() + 2;

    sort(v.begin(), v.end());

    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }

    return (0);
}