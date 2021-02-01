// B. Inflation

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        vector<ll> p(n);
        for (auto &el: p) cin >> el;

        vector<ll> prices(n);
        prices[0] = p[0];
        for (int i = 1; i < n; ++i) {
            prices[i] = prices[i-1] + p[i];
        }
        
        // Key ideas from - https://www.youtube.com/watch?v=vgxc1iXrAjo
        // His solution is - https://codeforces.com/contest/1476/submission/105869229
        ll ans = 0, tmp;
        for (int i = 1; i < n; ++i){
            tmp = (100 * p[i] + k - 1) / k;
            ans = max(ans, max(0LL, tmp - prices[i-1]));
        }

        cout << ans << endl;

    }

    return 0;
}
