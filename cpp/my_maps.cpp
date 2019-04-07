#include <iostream>
#include <map>

using namespace std;

int main ()
{
    multimap<int, int> my_map;
    my_map.insert({-1,0});
    my_map.insert({0,1});
    my_map.insert({1,2});
    my_map.insert({2,3});
    my_map.insert({-1,4});
    my_map.insert({-4,5});

    my_map.erase(-1);

    for (multimap<int, int>::iterator iter = my_map.begin(); iter != my_map.end(); ++iter) {
        cout << iter->first << " --> " << iter->second << endl;
    }
    
    return (0);
}
