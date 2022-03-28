// B. Prove Him Wrong

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> dp;
    int i = 1;

    int mx = (INT_MAX - 1) / 3;
    while (i < mx) {
        dp.push_back(i);
        i = i * 3 + 1;
    }
    int nn = size(dp);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        if (n > nn) {
            cout << "NO\n";
        }

        else {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << dp[i] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
