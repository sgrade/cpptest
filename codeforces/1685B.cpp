// B. Odd Subarrays

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

        int n;
        cin >> n;

        vector<int> a(n);
        for (int &el: a) cin >> el;

        int ans = 0;

        for (int i = 1; i < n; ++i) {
            if (a[i-1] > a[i]) {
                ++ans;
                ++i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
