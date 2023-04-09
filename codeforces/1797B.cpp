// B. Li Hua and Pattern

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }

        // Editorial - https://codeforces.com/blog/entry/114890
        // Sample solution - https://codeforces.com/contest/1797/submission/201272464
        bool ans = false;

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] != a[n - 1 - i][n - 1 - j]) {
                    ++cnt;
                }
            }
        }
        // Two cells are not equal to each other, but 
        // we need to change only one of them to be equal to the other.
        // And cnt will always be even.
        cnt /= 2;

        if (k == cnt) {
            ans = true;
        }
        else if (k > cnt) {
            int rem = k - cnt;
            // If rem != 0, but n is odd, we can still change the center and it will not affect the rotation.
            // Else we need to change a cell even number of times to stay the same.
            if (n % 2 != 0 || rem % 2 == 0) 
                ans = true;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
