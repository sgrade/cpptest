// A. Lucky?

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        int a = 0, b = 0;
        for (int i = 0; i < 3; ++i) {
            a += s[i] - 48;
        }
        for (int i = 3; i < 6; ++i) {
            b += s[i] - 48;
        }

        bool ans = a == b ? true : false;

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
