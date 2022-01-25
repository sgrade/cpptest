// B. Discounts

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<ll>> a(n, vector<ll>(3));
    for (auto &p: a) {
        cin >> p[0];
    }

    int m;
    cin >> m;

    vector<int> q(m);
    for (auto &el: q) {
        cin >> el;
    }

    sort(begin(a), end(a));
    a[0][1] = a[0][0];
    for (int i = 1; i < n; ++i) {
        a[i][1] = a[i][0] + a[i-1][1];
    }
    a[n-1][2] = a[n-1][0];
    for (int i = n-2; i > -1; --i) {
        a[i][2] = a[i][0] + a[i+1][2];
    }

    ll ans;
    
    int idx; // index of the free bar
    for (int i = 0; i < m; ++i) {
        idx = n - q[i];
        ans = a[idx][1] + a[idx+1][2] - a[idx][0];
        cout << ans << '\n';
    }

    return 0;
}
