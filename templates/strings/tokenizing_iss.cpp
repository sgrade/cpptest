#include <bits/stdc++.h>

using namespace std;


int main() {

    string s = "1,2,3,null,null,4,5";
    
    istringstream iss(s);
    string tmp;
    while (getline(iss, tmp, ',')) {
        cout << tmp << '\n';
    }

    /* Output:
    1
    2
    3
    null
    null
    4
    5
    */

    return 0;
}
