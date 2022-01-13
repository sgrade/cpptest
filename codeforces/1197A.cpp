// A. DIY Wooden Ladder

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }
        sort(begin(a), end(a));

        int ans = 0;

        if (n > 2) {
            ans = min(a[n-2] - 1, n - 2);
        }

        cout << ans << '\n';
    }

    return 0;
}
