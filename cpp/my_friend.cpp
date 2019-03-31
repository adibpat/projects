#include <iostream>
#include <string.h>

using namespace std;

class Complex;

class my_friend_class {
    string name;
public:
    my_friend_class () : name("Default name") {}
    my_friend_class (string my_name) : name(my_name) { }
    void show_friendship(Complex &c);
};

class another_friend_class {
    string name;
public:
    another_friend_class () : name("Default name") {}
    another_friend_class (string my_name) : name(my_name) { }
    void show_friendship(Complex &c);
};


class Complex {
    int a, b;
    int *a_ptr;
public:
    /* Constructors */
    Complex()
    {
        //cout << "\nconst 0 called";
        Complex::set_data();
    }
    Complex(int x)
    {
        //cout << "\nconst 1 called";
        Complex::set_data(x);
    }
    Complex(int x, int y)
    {
        //cout << "\nconst 2 called";
        Complex::set_data(x,y);
    }
    /* By default, copy const is a member by member copy */
    Complex(const Complex& c)
        : a(c.a), b(c.b), a_ptr(&a) /* This works instead of set_data() */
    {
        cout << "Copy const called\n";
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
    
    friend void print_complex(const Complex &c);
    friend class my_friend_class;
    friend void another_friend_class::show_friendship(Complex &c);
    friend Complex operator+(const Complex &, const Complex &);
    friend Complex operator-(const Complex &);
    friend ostream& operator<<(ostream&, Complex&);
    friend istream& operator>>(istream&, Complex&);
};

void print_complex (const Complex &c)
{
    cout << "Complex number is :" << c.a << " + " << c.b << "i\n";
}

void my_friend_class::show_friendship(Complex &c)
{
    cout << "my_friend_class: Complex number is :" << c.a << " + " << c.b << "i\n";
}

void another_friend_class::show_friendship(Complex &c)
{
    cout << "another_friend_class: Complex number is :" << c.a << " + " << c.b << "i\n";
}

Complex operator+ (const Complex &c1, const Complex &c2)
{
    return (Complex(c1.a+c2.a, c1.b+c2.b));
}

Complex operator-(const Complex &c)
{
    return (Complex(-c.a,-c.b));
}

ostream& operator<<(ostream &dout, Complex &c)
{
    cout << "Complex number is :" << c.a << " + " << c.b << "i" << endl;
    return cout;
}
istream& operator>>(istream &dout, Complex &c)
{
    cin>>c.a>>c.b;
    return cin;
}

int main ()
{
    Complex c1(5,4);
    print_complex(c1);

    /* Friend class demo */
    my_friend_class f1("Aditya");
    f1.show_friendship(c1);

    /* Friend function from another class */
    another_friend_class f2("Sharda");
    f2.show_friendship(c1);

    /* Frined function for operator overloading */
    Complex c2(2,3);
    Complex c3 = c1 + c2;
    print_complex(c3);

    /* Unary operator overload using friend function */
    c3 = Complex(-1,-2);
    print_complex(c3);
    c3 = -c3;
    print_complex(c3);

    /* Insertion operator and extraction operator */
    Complex c4;
    cin >> c4;
    cout << c4;
    
    return (0);
}
