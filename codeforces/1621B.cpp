// B. Integers Shop

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int inf = numeric_limits<int>::max();


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/98654
        
        vector<int> s(3), l(3), r(3);
        // segment, which includes min integer
        l[0] = inf;
        l[1] = 0;
        l[2] = inf;
        // segment, which includes max integer
        r[0] = inf;
        r[1] = 0;
        r[2] = inf;

        int ans = inf, ansL = inf, ansR = inf, ansLR = inf;

        for (int i = 0; i < n; ++i) {
            
            cin >> s[0] >> s[1] >> s[2];

            // Key ideas are from https://codeforces.com/contest/1621/submission/141497668
            
            if (s[0] < l[0]) {
                for (int i = 0; i < 3; ++i) {
                    l[i] = s[i];
                }
                ansL = s[2];
                ansLR = inf;
            }
            if (s[1] > r[1]) {
                for (int i = 0; i < 3; ++i) {
                    r[i] = s[i];
                }
                ansR = s[2];
                ansLR = inf;
            }

            if (s[0] == l[0]) {
                ansL = min(ansL, s[2]);
            }
            if (s[1] == r[1]) {
                ansR = min(ansR, s[2]);
            }
            if (s[0] == l[0] && s[1] == r[1]) {
                ansLR = min(ansLR, s[2]);
            }

            ans = min(ansL + ansR, ansLR);

            cout << ans << '\n';
        }
    }

    return 0;
}
