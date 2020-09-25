// A - Plural Form

#include <iostream>
#include <string>

using namespace std;


int main(){

    string s;
    getline(cin, s);

    if (s[s.size()-1] == 's') s+= "es";
    else s+= 's';

    cout << s << endl;

    return 0;
}