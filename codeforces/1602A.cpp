// A. Two Subsequences

#include <iostream>
#include <string>
#include <set>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        set<char> st(begin(s), end(s));

        char a = *begin(st);
        string b;

        bool flag = false;
        for (int i = 0; i < size(s); ++i) {

            if (flag || s[i] != a) {
                b += s[i];
                continue;
            }

            if (s[i] == a) {
                flag = true;
            }
        }

        cout << a << ' ' << b << endl;
    }

    return 0;
}
