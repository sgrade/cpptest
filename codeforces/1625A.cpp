// A. Ancient Civilization

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, l;
        cin >> n >> l;

        vector<int> cnt(l);

        // Some ideas from - https://codeforces.com/contest/1625/submission/142522790
        int x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            for (int j = 0; j < l; ++j) {
                int bit = (x >> j) & 1;
                cnt[j] += bit;
            }
        }

        int ans = 0;
        // Editorial - https://codeforces.com/blog/entry/99031
        int n2 = n / 2;
        for (int i = 0; i < l; ++i) {
            if (cnt[i] > n2) {
                ans += 1 << i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
