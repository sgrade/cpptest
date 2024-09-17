#include <bits/stdc++.h>

using namespace std;


int main() {

    string s = "1,2,3,null,null,4,5";

    istringstream iss(s);
    string tmp;
    while (getline(iss, tmp, ',')) {
        cout << tmp << '\n';
    }
    cout << endl;

    /* Output:
    1
    2
    3
    null
    null
    4
    5
    */

    cout << "Reuse the stringstream: " << endl;
    string s2 = "1 2 3";
    iss.clear();
    iss.str(s2);
    while (iss >> tmp)
        cout << tmp << ' ';
    cout << endl;

    return 0;
}
