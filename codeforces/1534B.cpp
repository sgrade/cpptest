// B. Histogram Ugliness

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ull = unsigned long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<ull> a(n + 2);
        int tmp;
        for (int i = 1; i < n+1; ++i) {
            cin >> a[i];
        }

        ull ans = 0ULL;

        for (int i = 1; i < n+1; ++i) {
            tmp = a[i] - max(a[i-1], a[i+1]);

            if (tmp > 0) {
                a[i] -= tmp;
                ans += tmp;

                ans += a[i] - min(a[i-1], a[i+1]);
            }

            else {
                tmp = a[i] - min(a[i-1], a[i+1]);
                if (tmp > 0) {
                    ans += tmp;
                }
            }
        }

        cout << ans << endl;

    }

    return 0;
}
