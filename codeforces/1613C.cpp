// C. Poisoned Dagger

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        long long h;
        cin >> n >> h;

        vector<int> a(n);
        for (int &el: a) {
            cin >> el;
        }

        long long ans = 1e18;

        long long l = 1, r = 1e18, k, hh;

        while (l <= r) {
            k = (r + l) / 2;

            hh = k;
            for (int i = n-1; i > 0; --i) {
                hh += min (0LL + a[i] - a[i-1], k);
            }

            if (hh >= h) {
                ans = k;
                r = k - 1;
            }
            else {
                l = k + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
