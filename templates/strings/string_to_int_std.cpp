#include <bits/stdc++.h>

using namespace std;


int main() {

    string s = "1234";
    cout << stoi(s) - 234 << endl;  // 1000

    s = "1";
    cout << stoi(s) + 1 << endl;    // 2

    cout << atoi(s.c_str()) + 1 << endl;    // 2

    return 0;
}
