// A. Keanu Reeves

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    string s;
    cin >> s;

    int zeros = count(s.begin(), s.end(), '0');
    int ones = n - zeros;

    if (zeros == ones){
        cout << 2 << endl;
        cout << s[0] << ' ';
        cout << s.substr(1, n-  1) << endl;
    }
    else {
        cout << 1 << endl;
        cout << s << endl;
    }

    return 0;
}
