// C. Number of Pairs

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, l, r;
        cin >> n >> l >> r;

        vector<int> a;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp < r) {
                a.push_back(tmp);
            }
        }
        sort(begin(a), end(a));

        long long ans = 0;
        for (int i = 0; i < a.size(); ++i) {
            // Editorial - https://codeforces.com/blog/entry/91637
            auto ub = upper_bound(begin(a), end(a), r - a[i]);
            ans += ub - begin(a);
            auto lb = lower_bound(begin(a), end(a), l - a[i]);
            ans -= lb - begin(a);
            // Exclude a[i] paired with itself
            if (l <= 2 * a[i] && 2 * a[i] <= r) {
                --ans;
            }
        }
        // Because all pairs are counted twice
        ans /= 2;

        cout << ans << endl;
    }

    return 0;
}
