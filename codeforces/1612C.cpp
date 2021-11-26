// C. Chat Ban

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;


// Source - https://www.geeksforgeeks.org/binary-search/
// Explanation - https://www.youtube.com/watch?v=qSPFa3Fj4jU
// Ideas from:
// https://codeforces.com/contest/1612/submission/136427045
// https://codeforces.com/contest/1612/submission/136430006
int binarySearch(ll k, ll l, ll r, ll x) {

    ll ans = 0;

    while (l < r) {
        
        ll m = (l + r) / 2;

        ll y;
        if (m <= k) {
            y = 1LL * m * (m + 1) / 2;
        }
        else {
            y = k * k;
            ll t = 2 * k - m - 1;
            y -= t * (t + 1) / 2;
        }

        if (y >= x) {
            r = m;
        }
        else {
            l = m + 1;
        }
        ans = l;
    }
 
    return ans;
}


int main() {

    int t;
    cin >> t;

    while (t--) {

        ll k, x;
        cin >> k >> x;

        ll ans = binarySearch(k, 1, 2*k-1, x);
        cout << (ans == 0 ? k : ans) << endl;
    }

    return 0;
}
