// A. Consecutive Sum

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int &el: a) {
            cin >> el;
        }

        // Editorial - https://codeforces.com/blog/entry/83109
        for (int i = 0; i < n; ++i) {
            a[i % k] = max(a[i % k], a[i]);
        }

        long long ans = accumulate(a.begin(), a.begin() + k, 0LL);

        cout << ans << '\n';
    }

    return 0;
}
