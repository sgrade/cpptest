// Chars and numbers

#include <iostream>

using namespace std;


int main(){

    string s, s1;

    s = '0' + ('0' - '0');
    s1 = '0' + ('0' - '0') / 2;
    cout << s << endl;
    cout << s1 << endl;

    s = '0' + ('1' - '0');
    s1 = '0' + ('1' - '0') / 2;
    cout << s << endl;
    cout << s1 << endl;

    s = '0' + ('2' - '0');
    s1 = '0' + ('2' - '0') / 2;
    cout << s << endl;
    cout << s1 << endl;

    return 0;
}
