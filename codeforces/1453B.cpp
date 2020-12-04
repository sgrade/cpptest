// B. Suffix Operations

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

int main(){

    int t;
    cin >> t;

    while(t--){

        ll n;
        cin >> n;

        vector<ll> a(n);
        for (auto &el: a) cin >> el;

        // Editorial - https://codeforces.com/blog/entry/85288

        ll ans = 0;
        for (int i = 1; i < n; ++i) ans += abs(a[i] - a[i-1]);

        // Corner cases
        ll mx = max(abs(a[0] - a[1]), abs(a[n-2] - a[n-1]));

        // The rest
        for (int i = 1; i < n-1; ++i){
            mx = max(mx, abs(a[i] - a[i-1]) + abs(a[i] - a[i+1]) - abs(a[i-1] - a[i+1]));
        }

        ans -= mx;
        cout << ans << endl;

    }

    return 0;
}
