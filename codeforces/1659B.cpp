// B. Bit Flipping

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        bool odd = k % 2;

        vector<int> ans(n);
        vector<int> flips(n);

        int i = 0;
        while (k > 0) {

            if (i == n) break;

            if (s[i] == '1') {
                if (odd) {
                    flips[i] = 1;
                }
            }

            else {
                if (!odd) {
                    flips[i] = 1;
                }
            }

            if (flips[i] == 1) {
                --k;
            }

            ans[i] = 1;
            ++i;
        }

        for (; i < n; ++i) {
            ans[i] = s[i] - '0';
            if (odd) {
                ans[i] = !ans[i];
            }
        }
        
        flips[n-1] += k;
        if (k % 2 != 0) {
            ans[n-1] = !ans[n-1];
        }

        for (int &el: ans) {
            cout << el;
        }
        cout << '\n';

        for (int &f: flips) {
            cout << f << ' ';
        }
        cout << '\n';
    }

    return 0;
}
