#include <bits/stdc++.h>

using namespace std;


int main() {

    string s = "1234";
    cout << stoi(s) - 234 << endl;

    s = "1";
    cout << stoi(s) + 1 << endl;

    cout << atoi(s.c_str()) + 1 << endl;

    return 0;
}