// A. Super Agent

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(){

    string tmp, s = "";
    for (int i = 0; i < 3; ++i) {
        getline(cin, tmp);
        s += tmp;
    }

    tmp = s;
    reverse(tmp.begin(), tmp.end());

    cout << (tmp == s ? "YES" : "NO") << endl;

    // Idea from - https://codeforces.com/problemset/problem/12/A

    return 0;
}
