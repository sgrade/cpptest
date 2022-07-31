// B. Luke is a foodie

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int &el: a) cin >> el;

        int ans = 0;

        int mn = a[n - 1], mx = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
            if (mx - mn > x * 2) {
                ++ans;
                mn = a[i];
                mx = a[i];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
