// B. Odd Grasshopper

#include <iostream>

using namespace std;
using ll = long long;


int main() {

    ll t;
    cin >> (t);

    while (t--) {

        ll x0, n;
        cin >> x0 >> n;

        ll ans;

        int nn = n % 4;
        bool x0_is_odd = x0 % 2;

        if (nn == 0) {
            ans = x0;
        }

        else if (nn == 1) {
            ans = x0_is_odd ? x0 + n : x0 - n;
        }

        else if (nn == 2) {
            ans = x0_is_odd ? x0 - 1 : x0 + 1;
        }

        else {
            ans = x0_is_odd ? x0 - (1 + n) : x0 + (1 + n);
        }

        cout << ans << endl;
    }

    return 0;
}
