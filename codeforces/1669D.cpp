// D. Colorful Stamp

#include <iostream>
#include <string>

using namespace std;


bool check (const int &r, const int &b) {
    if (r != 0) {
        if (b == 0) {
            return false;
        }
    }
    else if (b != 0) {
        if (r == 0) {
            return false;
        }
    }

    return true;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        bool ans = true;

        if (n == 1) {
            if (s[0] != 'W') ans = false;
        }

        else {           
           
            int r = 0, b = 0;
            for (int i = 0; i < n; ++i) {              
                if (s[i] == 'W') {
                    ans = check(r, b);
                    if (!ans) goto ANS;
                    r = 0;
                    b = 0;
                }
                else {
                    if (s[i] == 'R') ++r;
                    else ++b;
                }
            }

            ans = check(r, b);
        }

        ANS:
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
