// C. Long Jumps

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<ll> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        ll maxScore = 0;

        // Editorial - https://codeforces.com/blog/entry/86406
        vector<ll> dp(n);
        for (ll j = n-1; j >= 0; --j) {
            dp[j] = v[j];
            if (j + v[j] < n){
                dp[j] += dp[j + v[j]];
            }
            maxScore = max(maxScore, dp[j]);
        }

        cout << maxScore << endl;

    }

    return 0;
}
