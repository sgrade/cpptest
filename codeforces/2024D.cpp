// D. Skipping
// https://codeforces.com/contest/2024/problem/D

#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<ll> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= n; ++i)
            cin >> b[i];

        // Editorial - https://codeforces.com/blog/entry/135341
        vector<ll> penalty(n + 1, 2e18 + 1);
        penalty[1] = 0;

        int i = 2, max_i = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        if (b[1] > 1)
            pq.emplace(a[1], b[1]);
        while (!pq.empty()) {
            auto [points, b_i] = pq.top();
            pq.pop();
            if (b_i > max_i) {
                max_i = b_i;
                while (i <= max_i) {
                    penalty[i] = points;
                    if (b[i] > max_i)
                        pq.emplace(penalty[i] + a[i], b[i]);
                    ++i;
                }
            }
        }

        ll ans = 0;
        for (int i = 1; i <= n; ++i)
            a[i] += a[i - 1];
        for (int i = 1; i <= n; ++i)
            ans = max(ans, a[i] - penalty[i]);
        cout << ans << endl;
    }

    return 0;
}
