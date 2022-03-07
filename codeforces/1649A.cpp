// A. Game

#include <iostream>
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
        for (auto &el: a) {
            cin >> el;
        }

        int l = 0, r = n-1;

        for (; l < n-1; ++l) {
            if (a[l+1] == 0) {
                break;
            }
        }
        for (; r > 0; --r) {
            if (a[r-1] == 0) {
                break;
            }
        }

        int ans = max(r - l, 0);

        cout << ans << '\n';
    }

    return 0;
}
