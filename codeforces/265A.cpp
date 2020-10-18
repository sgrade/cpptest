// A. Colorful Stones (Simplified Edition)

#include <iostream>
#include <string>

using namespace std;


int main(){

    string s;
    string t;

    getline(cin, s);
    getline(cin, t);

    int i = 0;
    for (int j=0; j<t.size(); ++j){
        if (s[i] == t[j]) ++i;
    }

    cout << i+1 << endl;

    return 0;
}