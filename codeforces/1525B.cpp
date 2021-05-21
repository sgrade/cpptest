// B. Permutation Sort

#include <iostream>
#include <vector>
#include <algorithm>

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

        int ans = 0;

        if (!is_sorted(begin(a), end(a))) {
            const auto [mn, mx] = minmax_element(begin(a), end(a));
            if (a[0] == *mx && a[n-1] == *mn) {
                ans = 3;
            }
            else if (a[0] == *mn || a[n-1] == *mx) {
                ans = 1;
            }
            else {
                ans = 2;
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}
