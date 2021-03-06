#include <iostream>
#include "custom_date.h"


#ifndef __CUSTOM_PERSON_H__
#define __CUSTOM_PERSON_H__

using namespace std;

string occupation_list[] =
    {
        "Unemployed",
        "Engineer",
        "Doctor",
        "Teacher",
    };

class Person {
public:
    string get_name() const;
    // string get_occupation() const;
    void get_birthdate(Date&) const;
    // void set_name(string n);
    // void set_occupation(int oid);
    // void set_birthdate(Date&);
    Person(const string p_name = "Bully", int dd = 1, int mm = 1, int yy = 1960, int oid = 0);
    ~Person();
private:
    string name;
    Date birth_date;
    string occupation;
};

/*
 * Class Objects as members example
 * See how we call constructor for member objects
 */
Person::Person(const string p_name, int d, int m, int y, int occ_id)
    : birth_date(d,m,y)
{
    cout << "Default constructor called" << endl;
    name = p_name;
    occupation = occupation_list[occ_id];
}

Person::~Person()
{
    cout << "Destructor called" << endl;
}

string Person::get_name() const
{
    return (name);
}

void Person::get_birthdate(Date& date) const
{
    date = birth_date;
    return;
}

#endif /* End of header guard */
