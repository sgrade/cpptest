// D1. All are Same

#include <iostream>
#include <set>
#include <numeric>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        set<int> a;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            a.insert(tmp);
        }

        int ans = -1;

        if (size(a) > 1) {
            int mn = *begin(a);
            auto rit = rbegin(a);
            int prev = *rit;
            ++rit;
            ans = *rit - prev;
            while (rit != rend(a)) {
                // Editorial - https://codeforces.com/blog/entry/96034
                ans = gcd(ans, *rit - prev);
                prev = *rit;
                ++rit;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
