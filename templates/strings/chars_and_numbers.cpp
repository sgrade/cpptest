// Chars and numbers

#include <iostream>

using namespace std;


int main(){

    string s, s1;

    s = '0' + ('0' - '0');
    cout << s << endl;  // 0
    s1 = '0' + ('0' - '0') / 2;
    cout << s1 << endl;  // 0

    s = '0' + ('1' - '0');
    cout << s << endl;  // 1
    s1 = '0' + ('1' - '0') / 2;
    cout << s1 << endl; // 0

    s = '0' + ('2' - '0');
    cout << s << endl;  // 2
    s1 = '0' + ('2' - '0') / 2;
    cout << s1 << endl; // 1

    return 0;
}
