// A. Ezzat and Two Subsequences

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        sort(begin(a), end(a));

        // Editorial - https://codeforces.com/blog/entry/93703
        
        long double fa = 1.0 * accumulate(begin(a), begin(a) + (n-1), 0LL) / (n - 1);
        long double fb = a[n-1];

        long double ans = fa + fb;

        cout << setprecision(10) << ans << endl;

    }

    return 0;
}
