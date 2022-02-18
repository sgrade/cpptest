// A. Johnny and Ancient Computer

#include <iostream>

using namespace std;
using ull = unsigned long long;


ull base (ull x) {
    while (x % 2 == 0) {
        x /= 2;
    }
    return x;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        ull a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);

        // Editorial - https://codeforces.com/blog/entry/78355

        int ans = 0;
        
        ull base_a = base(a), base_b = base(b);
        if (base_a != base_b) {
            ans = -1;
        }

        else {
            b /= a;
            while (b >= 8 ) {
                b /= 8;
                ++ans;
            }
            if (b > 1) {
                ++ans;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
