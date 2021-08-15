// A. Mocha and Math
// Wrong answer on pretest 2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }
        sort(begin(a), end(a));

        int ans = a[0];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                ans = min(ans, a[i] & a[j]);
            }
        }

        cout << ans << endl;

    }

    return 0;
}
