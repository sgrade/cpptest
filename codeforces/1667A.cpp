// A. Make it Increasing

#include <iostream>
#include <vector>
#include <limits>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& el: a) cin >> el;

    ll ans = numeric_limits<ll>::max();

    // Editorial - https://codeforces.com/blog/entry/102013
    
    // I had the same idea. Only used below to correct the tmp formulas a bit
    // https://codeforces.com/contest/1667/submission/154083651
    for (int i = 0; i < n; ++i) {
        
        ll moves = 0;
        ll tmp, base;

        base = 0;
        for (int j = i - 1; j > -1; --j) {
            tmp = 1LL * base / a[j] + 1;
            moves += tmp;
            base = a[j] * tmp;
        }

        base = 0;
        for (int j = i + 1; j < n; ++j) {
            tmp = 1LL* base / a[j] + 1;
            moves += tmp;
            base = a[j] * tmp;
        }

        ans = min(ans, moves);
    }

    cout << ans << '\n';

    return 0;
}
