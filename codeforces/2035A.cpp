// A. Sliding
// https://codeforces.com/contest/2035/problem/A

#include <bits/stdc++.h>

using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        long long n, m, r, c;
        cin >> n >> m >> r >> c;

        long long ans = 0LL;
        ans += m - c;
        ans += 1LL * (n - r) * (m - 1);
        ans += 1LL * (n - r);
        ans += 1LL * (n - r) * (m - 1);
        cout << ans << endl;
    }

    return 0;
}
