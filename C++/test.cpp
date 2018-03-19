#include <iostream>
#include <vector>
#include <stddef.h>
#include <string>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

inline int sum(int &, int &);

int main (void) {

    cout << "Hello, World!" << endl;

    /* Reference variable usage */
    int a = 5, b = 6, c;
    c = sum(a,b);

    cout<<"Reference variable example: Sum of a(5) and b(6) is c = "<< c << endl;

    /************************************
     * Some Experimentation with vectors*
     ************************************/
    
    /*
     * This is a vector which will reallocate memory everytime new element is added
     * Obviously it will allocate some additional memory but that is not the topic of discussion
     */
    vector<int> v;

    v.push_back(11);
    v.push_back(33);

    cout << v.size() << endl; /* Answer is 2 */

    v.push_back(55);
    v.push_back(44);

    v[5] = 55; /* This is wrong because this vector does not have a 5th element yet. 
                  but it works */

    for (size_t i = 0; i < v.size(); i++) { /* Vector knows its own size */

        cout << v[i] <<endl; /* Can access elements like an array */

    } /* Will print only 11-44 */

    cout << v[10] << endl; /* This shows 0, don't know what is going on */

    vector<int>::iterator i = v.begin() + 2;

    sort(v.begin(), v.end());

    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }

    /*********************************
     * Some Experimentation with list*
     *********************************/
    list<int> l;
    
    l.push_back(11);
    l.push_back(33);

    cout << l.size() << endl; /* Answer is 2 */

    l.push_back(55);
    l.push_back(44);

    for (list<int>::iterator i = l.begin(); i != l.end(); ++i) {
        cout << *i << endl;
    }

    /*********************************
     * Some Experimentation with maps*
     *********************************/
    map<string, string> inner_db;
    map<int , map<string, string> > db;

    inner_db["addr"] = "localhost";
    inner_db["port"] = "50000";

    db[1] = inner_db;

    for (map<int, map<string,string> >::iterator i = db.begin(); i != db.end(); ++i) {
        cout << "{ " << i->first << ": " << endl;
        for (map<string, string>::iterator j = i->second.begin(); j != i->second.end(); ++j) {
            cout << "    { " << j->first << ": " << j->second << " }," << endl;
        }
        cout << "}" << endl;
    }

    cout << inner_db["addr"] << endl;

    /************************************
     * Some Experimentation with classes*
     ************************************/
    class Date {
        int d, m, y;
        //static Date default_date;
    public:
        Date(int dd=0, int mm=0, int yy=0);
    }
    Date::Date (int dd, int mm, int yy)
    {
        d = dd;
        m = mm;
        y = yy;
    }

    

    return(0);
}

int sum(int &x, int &y) {
    return(x+y);
}
