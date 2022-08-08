// B. Party

#include <iostream>
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

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        // Explanation - https://www.youtube.com/watch?v=6kgiDapRWe0
        // Idea for implementation - https://codeforces.com/contest/1711/submission/165563971

        int x, y;
        vector<int> count(n + 1);
        vector<pair<int, int>> adj(m + 1);
        for (int i = 1; i <= m; ++i) {
            cin >> x >> y;
            ++count[x];
            ++count[y];
            adj[i].first = x;
            adj[i].second = y;
        }

        // If number of pairs is even, there is no need to not invite someone
        //  so the unhappiness is zero
        if (m % 2 == 0) {
            cout << 0 << '\n';
            continue;
        }

        // To make number of pairs even, we can either 
        //  avoid inviting one person with odd number of friends or
        //  avoid inviting one pair with even number of friends in total.
        //  Whatever is less is the answer.
        int ans = numeric_limits<int>::max();
        for (int i = 1; i <= m; ++i) {
            x = adj[i].first;
            y = adj[i].second;

            // One person
            if (count[x] % 2 != 0) {
                ans = min(ans, a[x]);
            }
            if (count[y] % 2 != 0) {
                ans = min(ans, a[y]);
            }
            
            // One pair
            if (count[x] % 2 == 0 && count[y] % 2 == 0) {
                ans = min(ans, a[x] + a[y]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
