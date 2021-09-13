// C. RationalLee

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> a(n), w(k);
        
        for (auto &el: a) {
            cin >> el;
        }

        int friends_with_one_w = 0;
        for (auto &el: w) {
            cin >> el;
            if (el == 1) {
                ++friends_with_one_w;
            }
        }

        sort(begin(a), end(a), greater<int>());
        sort(begin(w), end(w));

        ll ans = 0;

        // Friends with one int
        ans += accumulate(begin(a), begin(a)+friends_with_one_w, 0LL) * 2;

        k -= friends_with_one_w;

        // Rest of max ints
        ans += accumulate(begin(a)+friends_with_one_w, begin(a)+friends_with_one_w+k, 0LL);

        // Min ints
        
        int idx_a = size(a) - 1;
        int idx_w = size(w) - 1;
        while (k--) {
            ans += a[idx_a];
            idx_a -= (w[idx_w] - 1);
            --idx_w;
        }

        cout << ans << endl;
    }

    return 0;
}
