// C. RationalLee
// Wrong answer on test 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
using ull = unsigned long long;


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

        ull ans = 0;

        // Friends with one int
        ans += accumulate(begin(a), begin(a)+friends_with_one_w, 0ULL) * 2;

        k -= friends_with_one_w;

        // Rest of max ints
        ans += accumulate(begin(a)+friends_with_one_w, begin(a)+friends_with_one_w+k, 0ULL);

        // Min ints
        int i = n-1, j = w.size()-1;
        while (k--) {
            ans += a[i];
            i -= w[j] - 2;
            --j;
            if (i < 0) {
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
