// A. King Moves

#include <iostream>
#include <string>

using namespace std;


int main(){

    string s;
    getline(cin, s);

    // Based on - https://codeforces.com/contest/710/submission/75919478
    bool x = s[0] == 'a' || s[0] == 'h';
    bool y = s[1] == '1' || s[1] == '8';

    cout << 8 - x * 3 - y * 3 + x * y;

    return 0;
}
