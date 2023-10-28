// B. Qingshan Loves Strings

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        bool ans = true;
        for (int i = 1; i < n; ++i) {
            if (s1[i] == s1[i - 1]) {
                ans = false;
                break;
            }
        }
        if (!ans) {
            if (s2[0] != s2[m - 1]) {
                ans = false;
                goto ANS;
            }
            for (int i = 1; i < m; ++i) {
                if (s2[i] == s2[i - 1]) {
                    ans = false;
                    goto ANS;
                }
            }
            for (int i = 1; i < n; ++i) {
                if (s1[i] == s1[i - 1]) {
                    if (s1[i] == s2[0]) {
                        ans = false;
                        goto ANS;
                    }
                }
            }
            ans = true;
        }
        ANS:
            cout << (ans ? "Yes\n" : "No\n");
    }

    return 0;
}
