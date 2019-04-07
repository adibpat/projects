#include <iostream>

using namespace std;

/* Function template */
template <class X>
X big(X a, X b)
{
    if (a > b) return (a);
    return (b);
}

/* Class Template */
template <class Y>
class ArrayList {
    struct Arep;
    Arep *s;
public:
    ArrayList ();
};

template<class Y>
struct ArrayList<Y>::Arep {
    int capacity;
    Y *arr_ptr;
};

template <class Y>
ArrayList<Y>::ArrayList ()
{
    s = new Arep(0, Y());
}

struct person {
    int age;
    char* name;    
};

int main ()
{
    cout << big(10.2, 3.2);
    ArrayList<int> list();
    person *adi = new person(0, char());
    return (0);
}
