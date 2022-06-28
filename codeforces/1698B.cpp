// B. Rising Sand

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

        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int &el: a) cin >> el;

        int ans = 0;

        if (k == 1) {
            ans = (n - 2 + 2 - 1) / 2;
        }

        else {
            for (int i = 1; i < n - 1; ++i) {
                if (a[i] > a[i - 1] + a[i + 1]) {
                    ++ans;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
