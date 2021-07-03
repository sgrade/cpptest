// C. Strange Function
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
using ull = unsigned long long;


// Based on isPrime
ull f (ull n){
    // if (n == 0 || n == 1) return false;
    ull i;
    for (i=2; i <= sqrtl(n); ++i){
        if (n % i != 0){
            return i;
        }
    }
    if (n % i == 0) {
        ++i;
    }
    return i;
}


int main() {

    int t;
    cin >> t;

    const int MOD = 1e9 + 7;

    vector<int> dp = {0, 2, 5};

    while (t--) {

        ull n;
        cin >> n;

        int ans;

        if (dp.size() > n) {
            ans = dp[n];
        }

        else {
            ull tmp;
            ans = *dp.rbegin();
            for (ull i = dp.size(); i < n + 1; ++i) {
                tmp = f(i);
                ans = (ans + tmp) % MOD;
                dp.push_back(ans);
            }
        }

        cout << ans << endl;

    }

    return 0;
}
