#include <iostream>
#include <string.h>

using namespace std;

class my_class {
    string name;
    int a;
public:
    my_class (string my_name) {
        //cout << "\nmy_class constructor called with name " << my_name;
        name = my_name;
    }
};

class Complex {
    int a, b;
    int *a_ptr;
    my_class m;
public:
    /* Constructors */
    Complex()
        : m("Default 0")
    {
        //cout << "\nconst 0 called";
        Complex::set_data();
    }
    Complex(int x)
        : m("Default 1")
    {
        //cout << "\nconst 1 called";
        Complex::set_data(x);
    }
    Complex(int x, int y)
        : m("Default 2")
    {
        //cout << "\nconst 2 called";
        Complex::set_data(x,y);
    }
    /* By default, copy const is a member by member copy */
    Complex(const Complex& c)
        : m("Default copy"), a(c.a), b(c.b), a_ptr(&a) /* This works instead of set_data() */
    {
        cout << "\nCopy const called";
        //Complex::set_data(c.a, c.b);
    }

    /* Member functions */
    void set_data(int x=0, int y=0)
    {
        a = x;
        b = y;
        a_ptr = &a;
    }
    void show_data()
    {
        cout << "\na = " << a << " b = " << b << " *a_ptr = " << *a_ptr;
    }
    Complex add (Complex& c)
    {
        return (Complex(a+c.a, b+c.b));
    }

    /* Operator Overload */
    Complex operator+(Complex& c)
    {
        /* Adds Complex objects */
        return (Complex(a+c.a, b+c.b));
    }
    Complex operator-(Complex &c) const
    {
        /* Subtraction operator overload */
        return (Complex(a-c.a, b-c.b));
    }
    /* Unary operator overload */
    Complex operator-() const
    {
        /* Unary operator overload. Negates Complex numbers */
        return (Complex(-a, -b));
    }
    Complex operator++()
    {
        /* Pre-increment operator overload */
        ++a;
        ++b;
        return (Complex(a,b));
    }
    Complex operator++(int) /* Post operators are identified by adding a int argument to the declaration */
    {
        /* Post operators overload */
        //cout<<"\nPost-increment called"; 
        Complex temp(this->a, this->b);
        this->a = ++a;
        this->b = ++b;
        return (temp);
    }
    Complex& operator=(const Complex &c)
    {
        //cout << "\nCopy assignment operator";
        a = c.a;
        b = c.b;
        a_ptr = &a;
        return (*this);
    }
};

int main ()
{
    Complex c1(5,4), c2(5), c3;
    c1.show_data();
    c2.show_data();
    c3.show_data();
    cout << "\nConst check done";

    c3 = c1.add(c2);
    c3.show_data();
    cout << "\nClass function check done";

    c3.set_data(0,0);
    c3 = c1 + c2;
    c3.show_data();
    cout << "\nOperator overload check done";

    Complex c4(c1);
    c1 = Complex(1,2);
    c4.show_data();
    cout << "\nCopy constructor check done";

    cout << "\nc3 data: "; c3.show_data();
    cout << "\nc1 data: "; c1.show_data();
    c4 = -c1;
    c4.show_data();

    ++c4;
    c4.show_data();

    c3=c4++;
    c3.show_data();
    c4.show_data();
    cout << "\nPre and post operator check done";

    Complex c6; /*= c1;*/ /* Copy const called here */
    c1.show_data();
    c6 = c1; /* Copy assignment called here */
    c1.set_data(0,0);
    cout << "\nc1 data: "; c1.show_data();
    cout << "\nc6 data: "; c6.show_data();
    
    return (0);
}
