// A. Not Shading

#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int inf = numeric_limits<int>::max();


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m, r, c;
        cin >> n >> m >> r >> c;
        --r;
        --c;

        string s;

        int ans = inf;
        
        // diff row, column
        int dr = inf, dc = inf;

        for (int i = 0; i < n; ++i) {
            cin >> s;
            for (int j = 0; ans != 0 && j < m; ++j) {
                if (s[j] == 'B') {
                    dr = abs(r - i);
                    dc = abs(c - j);
                    // Editorial - https://codeforces.com/blog/entry/99067
                    if (dr == 0 && dc == 0) {
                        ans = 0;
                    }
                    else if (dr == 0 || dc == 0) {
                        ans = min(ans, 1);
                    }
                    else {
                        ans = min(ans, 2);
                    }
                }
            }
        }

        cout << (ans == inf ? -1 : ans) << '\n';
    }

    return 0;
}
