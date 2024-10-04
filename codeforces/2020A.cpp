// A. Find Minimum Operations

#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n;
        cin >> k;

        if (k == 1) {
            cout << n << endl;
            continue;
        }

        // Editorial - https://codeforces.com/blog/entry/134516
        int ans = 0;
        while (n) {
            ans += n % k;
            n /= k;
        }
        cout << ans << endl;
    }

    return 0;
}
