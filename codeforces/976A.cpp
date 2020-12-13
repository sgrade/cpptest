// A. Minimum Binary Number

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n == 1) cout << s << endl;
    else {
        int zeros = count(s.begin(), s.end(), '0');
        cout << 1;
        for (int i = 0; i < zeros; ++i) cout << '0';
        cout << endl;
    }

    return 0;
}
