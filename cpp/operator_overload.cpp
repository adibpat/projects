#include <iostream>

using namespace std;

class complex {
private:
  int re, im;
public:
  complex(int r, int i): re(r), im(i)
  {
    cout<< "constructor called" << endl;
  }
  complex(const complex&);
  complex operator+(const complex&);
  complex operator*(const complex&);
  int operator==(const complex&);
  //complex operator=(const complex&);
  complex& operator=(const complex&);
  void print_complex() const ;
  int get_read () const { return re; }
  int get_imaginary () const { return im; }
};

/* Copy Constructor */
complex::complex(const complex& var)
{
  cout<<"copy constructor called"<<endl;
  if (this != &var){
    re = var.re;
    im = var.im;
  }
  return;
}

/* Add
 * a + ib + c + id = (a+c) + i(b+d)
 */
complex complex::operator+(const complex& var)
{
  cout<<"Operator overload + called" << endl;
  this->re += var.re;
  this->im += var.im;
  return (*this);
}

/* Multiply
 * (a+ib)*(c+id) = (a*c) + i(a*d + b*c) - (b*d)
 */
complex complex::operator*(const complex& var)
{
  cout<<"Operator overload * called" << endl;
  this->re = this->re*var.re - this->im*var.im;
  this->im = this->re*var.im + this->im*var.re;
  return (*this);
}

/* Copy assignment
 * complex b = a;
 */
 complex& complex::operator=(const complex& var)
 {
   cout<<"Operator overload = called" << endl;
   this->re = var.re;
   this->im = var.im;
   return (*this);
 }

int
complex::operator==(const complex& var)
{
  return (re == var.re && im == var.im);
}

void
complex::print_complex () const
{
  cout << "Real:"<<re << " Imaginary:"<<im << endl;
}

int main ()
{
  complex a = complex(1,3);
  complex b = complex(1,3);
  if (a==b){
    cout << "a and b are same" << endl;
  } else {
    cout << "a and b are different" << endl;
  }
  
  complex c = a+b;
  return (0);
}
