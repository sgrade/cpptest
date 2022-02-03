// C. Kill the Monster

#include <iostream>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;

    while (t--) {

        ll hc, dc;
        cin >> hc >> dc;

        ll hm, dm;
        cin >> hm >> dm;

        ll k, w, a;
        cin >> k >> w >> a;

        bool ans = false;

        // Rounds to kill monster and character
        ll rtk_m, rtk_c;

        // Units of weapon and armor modifiers;
        ll ww, aa;
        // dc and hc upgraded by the above
        ll dcu, hcu;

        for (int i = 0; i <= k; ++i) {
             
            ww = 0 + i;
            aa = k - i;

            dcu = dc + ww * w;
            hcu = hc + aa * a;

            rtk_m = (hm + dcu - 1) / dcu;
            rtk_c = (hcu + dm - 1) / dm;

            if (rtk_m <= rtk_c) {
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
