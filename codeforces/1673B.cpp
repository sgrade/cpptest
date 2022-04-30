// B. A Perfectly Balanced String?
// Time limit exceeded on test 3

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <set>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        set<char> ss(s.begin(), s.end());
        int n_ss = ss.size();

        int n = s.size();

        bool ans = true;

        if (n_ss > 1) {

            vector<map<char, int>> v(n);

            // Ideas are from https://www.geeksforgeeks.org/queries-frequencies-characters-substrings/
            
            for (int i = 0; i < n; ++i) ++v[i][s[i]];

            for (int i = 1; i < n; i++) {
                for (auto &ch: ss) {
                    v[i][ch] += v[i-1][ch];
                }
            }

            int l = 0, r = 0, d;
            int mn, mx, cur;
            for (d = 1; l + d < n; ++d) {
                for (l = 0; l < n - 1; ++l) {
                    for (r = l + d; r < n; ++r) {
                        mn = numeric_limits<int>::max();
                        mx = 0;
                        for (auto &ch: ss) {
                            cur = v[r][ch];
                            if (l != 0) cur -= v[l-1][ch];
                            mx = max(mx, cur);
                            mn = min(mn, cur);
                            if (mx - mn > 1) {
                                ans = false;
                                goto ANS;
                            }
                        }
                    }
                }
            }
        }

        ANS:
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
