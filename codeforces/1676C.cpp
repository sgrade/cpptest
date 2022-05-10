// C. Most Similar Words

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;


inline int diff (char a, char b) {
    
    int x, y;

    x = a - 48;
    y = b - 48;

    return abs(x - y);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<string> v(n);
        for (string &s: v) cin >> s;

        int ans = numeric_limits<int>::max();

        for (int j = 1; j < n; ++j) {
            int cur_ans;
            for (int i = 0; i < j; ++i) {
                cur_ans = 0;
                for (int k = 0; k < m; ++k) {
                    cur_ans += diff(v[j][k], v[i][k]);
                }
                ans = min(ans, cur_ans);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
