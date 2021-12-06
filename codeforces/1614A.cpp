// A. Divan and a Store

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, l, r, k;
        cin >> n >> l >> r >> k;

        map<int, int> a;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++a[tmp];
        }

        int ans = 0;

        auto lit = a.lower_bound(l);
        while (lit != end(a)) {
            if (lit->first > r) {
                break;
            }
            ans += min(lit->second, k / lit->first);
            k -= lit->first * lit->second;
            if (k <= 0) {
                break;
            }
            ++lit;
        }

        cout << ans << endl;
    }

    return 0;
}
