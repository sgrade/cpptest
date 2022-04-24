// H. Maximal AND

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int &el: a) cin >> el;

        int ans = 0;

        int tmp;
        // Key ideas follow https://codeforces.com/contest/1669/submission/154324717
        for (int i = 30; i > -1; --i) {
            tmp = 1 << i;
            int cnt = n;
            for (int j = 0; j < n; ++j) {
                if (a[j] & tmp) --cnt;
            }
            if (cnt <= k) {
                k -= cnt;
                ans += tmp;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
