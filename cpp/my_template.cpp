#include <iostream>

using namespace std;

/* Function template */
template <class X>
X big(X a, X b)
{
    if (a > b) return (a);
    return (b);
}

template <class Y> class ArrayList {
    struct ControlBlock {
        int capacity;
        Y *arr_ptr;
    };
    ControlBlock *s;
public:
    ArrayList (int x)
    {
        s = new ControlBlock;
        s->capacity = x;
        s->arr_ptr = new Y[s->capacity];
    }
};

int main ()
{
    cout << big(10.2, 3.2);
    ArrayList<int> list(4);
    return (0);
}
