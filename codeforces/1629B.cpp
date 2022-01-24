// B. GCD Arrays

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int l, r, k;
        cin >> l >> r >> k;

        // Editorial - https://codeforces.com/blog/entry/99276

        int ans = 0;

        if (l == r) {
            if (l == 1 && r == 1) {
                ans = 1e9 + 1;
            }
        }

        else {
            ans = (r - l + 1) / 2;
            if ((l & 1) & (r & 1)) {
                ++ans;
            }
        }

        cout << (ans <= k ? "YES" : "NO") << '\n';
    }

    return 0;
}
