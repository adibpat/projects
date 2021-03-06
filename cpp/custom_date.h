#include <iostream>

#ifndef __CUSTOM_DATE_H__
#define __CUSTOM_DATE_H__

using namespace std;

const string month[13] = {
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
    "December",
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

    /* In-class function definition */
    void fill_cache() const { cache = month[m]; }

    /* Static members
     * static members have exactly one copy per class
     * This one copy needs to be defined separately.
     */
    static Date default_date;

public:
    /* How to write a constructor
       class_name(arg_list); // 1

       class_name(arg_list): // 2
       member1_class_name(member1_class_arg_list), member2_class_name(member2_class_arg_list)
       {
           //constructor code
       }
     */
    Date(int dd=0, int mm=0, int yy=0);

    /* How to write a copy constructor
       class_name(const class_name&);
       e.g :
       Date today = Date(01,02,1992);
       Date tomorrow = today;
       Here copy constructor is called for tomorrow. Today is sent as const reference
       tomorrow.operator=(today) -> is how it is executed
     */
    Date(const Date&); // This is the copy constructor

    /* How to write a operator overload function */
    /* */
    Date& operator=(const Date&); // This is copy assignment
    /* static member function cannot be invoked for a particular object */
    static void set_default(int, int, int);
    void print_date();
    /*
     * const keyword after (empty) argument list
     * indicates that these functions do not modify members
     */
    //int day () const { return d++; } -> will throw error
    int get_day() const { return d; }
    int get_month() const { return m; }
    int get_year() const { return y; }
    string get_string() const;
    /*
     * Self reference
     * Such functions returning reference can be used for chaining
     * See implementation of add_dmy()
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

string Date::get_string() const
{
    if (cache_valid == 0) {
        fill_cache();
        cache_valid = 1;
    }
    return (cache);
}

/* This is invoked when a new object is created as a copy */
Date::Date (const Date& date)
{
    //cout << "Copy constructor used"<<endl;
    if (this != &date) {
        d = date.d;
        m = date.m;
        y = date.y;
    }
}

/* This is invoked during normal copy operations */
Date& Date::operator=(const Date& date)
{
    //cout << "Copy assignment used"<<endl;
    if (this != &date) {
        d = date.d;
        m = date.m;
        y = date.y;
    }
    return *this;
}


#endif /* End of header guard */
