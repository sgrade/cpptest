// D. Skipping

#include <bits/stdc++.h>

using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= n; ++i)
            cin >> b[i];

        // Editorial - https://codeforces.com/blog/entry/135341
        // Based on https://codeforces.com/blog/entry/135341
        vector<int> seen(n + 1, 1e9 + 1);
        seen[1] = 0;
        int i = 2, cur_max = 1;
        priority_queue<pair<int, int>> pq;
        if (b[1] > 1)
            pq.emplace(-1 * a[1], b[1]);
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (cur.second > cur_max) {
                cur_max = cur.second;
                while (i <= cur_max) {
                    seen[i] = -1 * cur.first;
                    if (b[i] > cur_max)
                        pq.emplace(-1 * (seen[i] + a[i]), b[i]);
                    ++i;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
            a[i] += a[i - 1];
        for (int i = 1; i <= n; ++i)
            ans = max(ans, a[i] - seen[i]);
        cout << ans << endl;
    }

    return 0;
}
