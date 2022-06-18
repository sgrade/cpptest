// A. Subrectangle Guess

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        int cur;
        int mx = numeric_limits<int>::min();
        int mx_r, mx_c;

        int r, c;
        for (r = 1; r < n + 1; ++r) {
            for (c = 1; c < m + 1; ++c) {
                cin >> cur;
                if (cur > mx) {
                    mx = cur;
                    mx_r = r;
                    mx_c = c;
                }
            }
        }

        int ans_r, ans_c;

        ans_r = max(mx_r, n - mx_r + 1);
        ans_c = max(mx_c, m - mx_c + 1);

        cout << ans_r * ans_c << '\n';
    }

    return 0;
}
