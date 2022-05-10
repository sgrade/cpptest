// E. Eating Queries

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

        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int &el: a) cin >> el;

        sort(a.begin(), a.end(), greater<int>());

        vector<int> dp(n + 1);

        long long sm = 0;
        for (int i = 0; i < n; ++i) {
            sm += a[i];
            dp[i+1] = sm;
        }

        vector<int>::iterator it;

        int tmp, ans;
        for (int i = 0; i < q; ++i) {
            cin >> tmp;

            it = lower_bound(dp.begin(), dp.end(), tmp);

            if (it != dp.end()) {
                ans = distance(dp.begin(), it);
                cout << ans << '\n';
            }
            else cout << "-1\n";
        }
    }

    return 0;
}
