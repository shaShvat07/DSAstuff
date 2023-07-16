#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {

    unordered_map<string , int> ourmap;

    // Insert
    pair<string , int> p("lahot" , 1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    // Find or access
    cout << ourmap["lahot"] << endl;
    cout << ourmap.at("def") << endl;

    // Size
    cout << "Size before : "  << ourmap.size() << endl;
    // Cause and effect!
    cout << ourmap["idk"] << endl;
    // Size
    cout << "Size after : "  << ourmap.size() << endl;

    // Check Presence 
    if (ourmap.count("idk") > 0 )
    {
        cout << "idk it's somehow there!" << endl;
    }

    // Erase 
    ourmap.erase("idk");
    // Size
    cout << "Size after erase : "  << ourmap.size() << endl;
        if (ourmap.count("idk") > 0 )
    {
        cout << "idk is it there now" << endl;
    }

    ourmap["abc"] = 69;
    ourmap["abc2"] = 90;

    // find 
    unordered_map<string, int>::iterator it2 = ourmap.find("abc");

    unordered_map<string, int>::iterator it;
    it = ourmap.begin();

    while( it != ourmap.end())
    {
        cout << "Key : " << it->first << "  Value : " << it->second << endl;
        it++;
    }

    ourmap.erase(it2);
    it = ourmap.begin();

        while( it != ourmap.end())
    {
        cout << "Key : " << it->first << "  Value : " << it->second << endl;
        it++;
    }

    return 0;
}