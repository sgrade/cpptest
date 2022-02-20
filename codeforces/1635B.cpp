// B. Avoid Local Maximums

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

        int ans = 0;

        auto mn_mx_it = minmax_element(begin(a), end(a));
        int mn = *mn_mx_it.first, mx = *mn_mx_it.second;

        // forward, backward
        int f = 1, b = n - 2;

        while (true) {
            // forward
            for (; f < n - 1 && f <= b; ++f) {
                if (a[f-1] < a[f] && a[f] > a[f+1]) {
                    a[f+1] = f == n-2? a[f] : max(a[f], a[f+2]);
                    ++f;
                    ++ans;
                    break;
                }
            }

            // backward
            for (; b > 0 && b <= f; --b) {
                if (a[b-1] < a[b] && a[b] > a[b+1]) {
                    a[b-1] = b == 1 ? a[b] : max(a[b], a[b-2]);
                    --b;
                    ++ans;
                    break;
                }
            }

            if (f > b) {
                break;
            }
        }

        cout << ans << '\n';
        for (auto &el: a) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}
