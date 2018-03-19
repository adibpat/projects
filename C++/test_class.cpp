#include <iostream>
#include <string>
#include <vector>
#include "custom_date.h"
#include "custom_person.h"

using namespace std;

void add_dmy (Date&, int, int, int);

void test_class_person()
{
    Person p = Person("Aditya", 15, 9, 1992, 1);
    cout << "P object's name is " << p.get_name() << endl;
    Date p_bd;
    p.get_birthdate(p_bd);
    cout << "P's bday day is "<< p_bd.get_day() << endl;
}

void test_class_date()
{
    Date my_bday;
    cout << "My birth date is ";
    my_bday.print_date();
    /* default is changed here from 15.9.1992 to 27.8.1992 */
    Date::set_default(27,8,1992);
    cout << "Default changed"<< endl;
    Date sha_bday;
    cout << "Sharda's bday is ";
    sha_bday.print_date();
    /* Demonstration of copying class object */
    Date copy_of_sha_bday = sha_bday;
    cout << "Copy of Sharda's bday is ";
    copy_of_sha_bday.print_date();
    /* Demonstration of constant member functions */
    cout << "Get day using const member function on my_day : " << my_bday.get_day()<< endl;
    /*
     * Demonstration of self reference
     * Remember, this is a pointer to the object for which fn was invoked
     */
    Date copy_of_my_bday = my_bday;
    //Date& ref_date = copy_of_my_bday;
    add_dmy(copy_of_my_bday, 1,1,1);
    cout << "copy_of_my_bday after add_dmy is ";
    copy_of_my_bday.print_date();
    cout << "Month in string is " << my_bday.get_string() << endl;
    copy_of_my_bday = sha_bday;
}
    
int main ()
{
    //test_class_date();
    test_class_person();
    return (0);
}

void add_dmy (Date& date, int d, int m, int y)
{
    date.add_day(d).add_month(m).add_year(y);
}
