// Example usage: https://leetcode.com/problems/find-common-characters/

#include <bits/stdc++.h>

using namespace std;


int main() {

    int ascii_value;

    ascii_value = 65;
    cout << char(ascii_value) << endl;  // a
    ascii_value = 97;
    cout << char(ascii_value) << endl;  // a

    cout << endl;

    ascii_value = 65;
    cout << string(1, ascii_value) << endl;  // A
    ascii_value = 97;
    cout << string(1, ascii_value) << endl;  // a

    cout << endl;

    // !!! to_string does not convert ascii value to char, but prints the string version of the ascii value !!!
    cout << char(ascii_value) << endl;  // a
    cout << to_string(ascii_value) << endl;  // 97
    cout << to_string(char(ascii_value)) << endl;  // 97

    return 0;
}
