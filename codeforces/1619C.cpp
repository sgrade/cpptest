// C. Wrong Addition

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        string sa, ss;
        cin >> sa >> ss;

        int na = size(sa);
        int ns = size(ss);

        vector<int> a(na), s(ns);
        for (int i = 0; i < na; ++i) {
            a[i] = sa[i] - '0';
        }
        for (int i = 0; i < ns; ++i) {
            s[i] = ss[i] - '0';
        }

        vector<int> b;
        bool ans = true;

        int shift = ns - na;
        int i = na - 1;
        int j = i + shift;
        int x;
        for (; i > -1 && j > -1; --i) {
            if (s[j] >= a[i]) {
                x = s[j] - a[i];
                b.push_back(x);
            }
            else {
                if (j > 0 && s[j-1] == 1) {
                    x = s[j-1]*10 + s[j] - a[i];
                    b.push_back(x);
                    --j;
                }
                else {
                    ans = false;
                    break;
                }
            }
            --j;
        }
        if (j == -1 && i > -1) {
            ans = false;
        }
        if (ans) {
            for (; j > -1; --j) {
                b.push_back(s[j]);
            }
        }

        if (ans) {
            i = size(b) - 1;
            while (b[i] == 0) {
                --i;
            }
            for (; i > -1; --i) {
                cout << b[i];
            }
            cout << endl;
        }
        else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
