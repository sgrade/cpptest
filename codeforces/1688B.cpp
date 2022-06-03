// B. Patchouli's Magical Talisman

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

        vector<int> a;
        int odd = 0, even = 0, tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp % 2 == 0) {
                ++even;
                a.push_back(tmp);
            }
            else ++odd;
        }

        int ans = 0;

        if (odd > 0) ans = even;

        else {
            int ops = 0;
            while (true) {
                ++ops;
                for (int i = 0; i < even; ++i) {
                    a[i] /= 2;
                    if (a[i] % 2 != 0) {
                        ans = ops + even - 1;
                        goto ANS;
                    }
                }
            }
        }

        ANS:
        cout << ans << '\n';
    }

    return 0;
}
