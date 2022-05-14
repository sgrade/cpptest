// A. AvtoBus

#include <iostream>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        ll n;
        cin >> n;

        bool ans = false;

        ll mn, mx, rem, x;

        if (n % 2 == 0) {

            // looking for mn
            bool found_min = false;
            ll cnt_min = 0;
            while (cnt_min < 4) {
                x = n - 1LL * 4 * cnt_min;
                if (x < 0) {
                    break;
                }
                rem = x % 6;
                if (rem == 0) {
                    found_min = true;
                    mn = 1LL * x / 6;
                    mn += cnt_min;
                    break;
                }
                ++cnt_min;
            }

            // looking for mx
            bool found_max = false;
            ll cnt_max = 0;
            while (cnt_max < 3) {
                x = n - 1LL * 6 * cnt_max;
                if (x < 0) {
                    break;
                }
                rem = x % 4;
                if (rem == 0) {
                    found_max = true;
                    mx = 1LL * x / 4;
                    mx += cnt_max;
                    break;
                }
                ++cnt_max;
            }

            if (found_min && !found_max) {
                mx = mn;
                ans = true;
            }
            if (found_max && !found_min) {
                mn = mx;
                ans = true;
            }
            if (found_min && found_max) {
                ans = true;
            }
        }

        if (ans) {
            cout << mn << ' ' << mx << '\n';
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}
