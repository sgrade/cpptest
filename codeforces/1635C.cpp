// C. Differential Sorting

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

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        // Editorial - https://codeforces.com/blog/entry/100153

        int ans = -1;
        vector<vector<int>> output;

        if (a[n-2] <= a[n-1]) {

            if (a[n-1] < 0) {
                if (is_sorted(begin(a), end(a))) {
                    ans = 0;
                }
            }

            else {
                ans = n - 2;
                int x = 1, y = n-1, z = n;
                while (x < y) {
                    output.push_back({x, y, z});
                    ++x;
                }
            }
        }

        cout << ans << '\n';
        if (ans > 0) {
            for (auto &v: output) {
                cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
            }
        }
    }

    return 0;
}
