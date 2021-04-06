// B. Replace and Keep Sorted
// Time limit exceeded on test 3

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ull = unsigned long long;


int main() {

    int n, q, k;
    cin >> n >> q >> k;

    vector<int> a(n+2);
    a[0] = 0;
    for (int i = 1; i < n+1; ++i) {
        cin >> a[i];
    }
    a[n+1] = k;

    vector<int> dp(n+2);
    dp[0] = 0;
    for (int i = 1; i < n+1; ++i) {
        dp[i] = max(0, a[i+1] - a[i-1] - 2);
    }
    
    int l, r, ans;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        // l and r are 1-indexed, but we already compensated it before by inserting dp[0] = 0
        ans = accumulate(dp.begin()+l, dp.begin()+r+1, 0ULL);
        
        // Correction for range from 1 to a[l-1], which are not included in dp
        ans += a[l-1];
        // Correction for range from a[r] to a[r+1], which are included in dp, but should not
        ans -= max(0, a[r+1] - a[r] - 1);
        // Correction for range from a[r] to k
        ans += max(0, k - a[r]);

        cout << ans << endl;
    }

    return 0;
}
