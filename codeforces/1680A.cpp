// A. Minimums and Maximums

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int ans = l1 + l2;

        int l = max(l1, l2);
        int r = min(r1, r2);

        if (l <= r) {
            ans = l;
        }



        cout << ans << '\n';
    }

    return 0;
}
