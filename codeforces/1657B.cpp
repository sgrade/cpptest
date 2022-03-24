// B. XY Sequence

#include <iostream>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, B, x, y;
        cin >> n >> B >> x >> y;

        int prev = 0;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {

            if (prev + x > B) {
                prev -= y;
            }
            else {
                prev += x;
            }

            ans += prev;
        }

        cout << ans << '\n';
    }

    return 0;
}
