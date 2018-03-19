#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<string> month {
    "STUB",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
        };

/************************************
 * Some Experimentation with classes*
 ************************************/
class Date {
    int d, m, y;
    /*
     * Mutable means not const
     * const member functions can modify mutable variables
     */
    mutable bool cache_valid;
    mutable string cache;
    /* static members have exactly one copy per class
     * This one copy needs to be defined separately.
     */
    static Date default_date;
public:
    Date(int dd=0, int mm=0, int yy=0);
    /* static member function cannot be invoked for a particular object */
    static void set_default(int, int, int);
    void print_date();
    void fill_cache() const;
    /*
     * const keyword after (empty) argument list
     * indicates that these functions do not modify members
     */
    //int day () const { return d++; } -> will throw error
    int day() const { return d; }
    int month() const { return m; }
    int year() const { return y; }
    string get_string() const;
    /*
     * Self reference 
     */
    Date & add_year(int);
    Date & add_month(int);
    Date & add_day(int);
};

/*
 * Definition of static members is a must 
 * otherwise we get symbol not found error
 */
Date Date::default_date(15,9,1992);

void Date::set_default(int dd, int mm, int yy)
{
    Date::default_date = Date(dd, mm, yy);
}

Date::Date (int dd, int mm, int yy)
{
    d = dd ? dd: default_date.d;
    m = mm ? mm: default_date.m;
    y = yy ? yy: default_date.y;
    cache_valid = 0;
}

void Date::print_date ()
{
    cout<< d << "/" << m << "/" << y << endl;
}

Date& Date::add_year (int n)
{
    y+=n;
    return *this;
}

Date& Date::add_month (int n)
{
    m+=n;
    return *this;
}

Date& Date::add_day (int n)
{
    d+=n;
    return *this;
}

void Date::fill_cache () const
{
    cache = month[m];
}

string Date::get_string() const
{
    if (cache_valid == 0) {
        cout<< "Filling cache" <<endl;
        fill_cache();
        cache_valid = 1;
    }
    return (cache);
}
/* End of Date APIs */

void add_dmy (Date& date, int d, int m, int y)
{
    date.add_day(d).add_month(m).add_year(y);
}

int main ()
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
    cout << "Get day using const member function on my_day : " << my_bday.day()<< endl;
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
    return (0);
}
