// C. Andrew and Stones

#include <iostream>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        ll even = 0, odd = 0;
        int cnt_odd = 0;
        ll tmp;

        ll ans = 0;
        
        cin >> tmp;
        for (int i = 1; i < n-1; ++i) {
            cin >> tmp;
            if ((tmp & 1) == 0) {
                even += tmp;
                ans += tmp / 2;
            }
            else {
                odd += tmp;
                ++cnt_odd;
                ans += (tmp + 1) / 2;
            }
        }
        cin >> tmp;
        
        // Editorial - https://codeforces.com/blog/entry/99883
        if (cnt_odd > 0) {
            if (odd + even == cnt_odd || n == 3) {
                ans = -1;
                goto ANS;
            }
        }

        ANS:
        cout << ans << '\n';
    }

    return 0;
}
