// C. Banknotes

#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        ull n, k;
        cin >> n >> k;

        // ans can be represented with k+1 banknotes
        ++k;

        vector<ull> a;
        for (int i = 0; i < n; ++i) {
            int tmp, x = 1;
            cin >> tmp;
            for (int j = 1; j < tmp + 1; ++j) {
                x *= 10;
            }
            a.push_back(x);
        }
        a.push_back(1e18);

        ull ans = 0;

        // Some inspiration is taken from here - https://codeforces.com/contest/1606/submission/133459336

        for (int i = 0; i < n; ++i) {
            ull x = a[i+1] / a[i] - 1;
            ans += min(x, k) * a[i];
            k -= min(x, k);
        }

        cout << ans << endl;
    }

    return 0;
}
