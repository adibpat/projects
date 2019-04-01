#include <iostream>

using namespace std;

class A {
public:
    void f1 () { cout << "Parent f1" << endl; }
    virtual void f2 () { cout << "Parent f2" << endl; }
    virtual void f3 () { cout << "Parent f3" << endl; }
};

class A_abstract {
public:
    virtual void fun()=0; // pure virtual function
};

class B : public A {
public :
    void f1 () { cout << "Child f1" << endl; }
    void f2 () { cout << "Child f2" << endl; }
    void f3 (int x) { cout << "Child f3" << endl; }
};

class C : public A_abstract {
public:
    void fun () { cout << "Child fun" << endl; }
};

int main ()
{
    A a, *a_ptr;
    B b;
    a.f1(); // calls parent f1 - OK
    a.f2(); // calls parent f2 - OK
    a.f3();
    b.f1(); // calls child f1 - OK
    a_ptr = &b; 
    a_ptr->f1(); // problem in function over-riding. Calls parent f1
    a_ptr->f2(); // calls child f2 - OK - virtual fuctins helped
    a_ptr->f3(); // parent f3 is called here even when object type is B (child).

    C c;
    c.fun();
    return (0);
}
