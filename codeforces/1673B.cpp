// B. A Perfectly Balanced String?
// NOT CHECKED

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

            vector<vector<int>> v(n, vector<int>(26));

            // Ideas are from https://www.geeksforgeeks.org/queries-frequencies-characters-substrings/
            
            for (int i = 0; i < n; ++i) ++v[i][s[i] - 'a'];

            for (int i = 1; i < n; i++) {
                for (int j = 0; j < 26; j++)
                    v[i][j] += v[i - 1][j];
            }

            int l = 0, r = 0, d;
            int mn, mx, cur;
            for (d = 2; l + d < n; ++d) {
                for (l = 0; l < n - 2; ++l) {
                    for (r = l + d; r < n; ++r) {
                        mn = numeric_limits<int>::max();
                        mx = 0;
                        for (int i = 0; i < 26; ++i) {
                            cur = v[r][i] - v[l][i];
                            mx = max(mx, cur);
                            mn = min(mx, cur);
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
