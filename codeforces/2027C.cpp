// C. Add Zeros

#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void dfs (ll len_need, map<ll, vector<ll>>& adj, set<ll>& seen) {
    if (seen.find(len_need) != seen.end())
        return;
    seen.emplace(len_need);
    for (const ll& len_get: adj[len_need]) {
        dfs (len_get, adj, seen);
    }
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        
        // Editorial - https://codeforces.com/blog/entry/135558
        map<ll, vector<ll>> adj;
        for (int i = 1; i < n; ++i) {
            ll len_need = a[i] + i;
            ll len_get = len_need + i;
            adj[len_need].emplace_back(len_get);
        }

        set<ll> seen;
        dfs(n, adj, seen);
        ll ans = *seen.rbegin();
        cout << ans << endl;
    }

    return 0;
}
