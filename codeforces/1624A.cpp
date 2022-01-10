// A. Plus One on the Subset

#include <iostream>
#include <limits>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int mn = numeric_limits<int>::max(), mx = numeric_limits<int>::min();

        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            mn = min(mn, tmp);
            mx = max(mx, tmp);
        }

        int med = (mn + mx) / 2;

        int ans = (mx - med) + (med - mn);

        cout << ans << '\n';
    }

    return 0;
}
