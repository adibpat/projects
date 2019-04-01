#include <iostream>

using namespace std;

class Mother {
private:
    int privatev;    
protected:
    int protectedv;
public:
    int publicv;    
};

class Daughter : protected Mother {
public:
    void doSomething();
};

class Son : private Mother {
public:
    void doSomething();
};

/*
 * For protected inheritance, public and protected members are accessible 
 * via member function of derived class and friends and derived classed and 
 * friends of derived class.
 *
 * Only difference between public and protected inheritance is 
 * conversion of D* to B*. Anyone can do the conversion for public inheritance.  
 */

void Daughter::doSomething()
{
    publicv = 10;
    protectedv = 20;
}

void Son::doSomething()
{
    publicv = 10;
    protectedv = 20;
}

int main ()
{
    Daughter sharda;
    sharda.doSomething();
    
    Son alia;
    alia.doSomething();
    return (0);
}
