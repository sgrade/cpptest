// A. XOR Mixup

#include <iostream>
#include <algorithm>
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
        for (int &el: a) cin >> el;

        int ans;

        if (n == 2) {
            ans = a[0];
        }

        else {
            for (int i = 0; i < n; ++i) {
                int x = a[i];
                vector<int> tmp;
                for (int j = 0; j < n; ++j) {
                    if (i == j) {
                        continue;
                    }
                    tmp.push_back(a[j]);
                }
                for (int j = 1; j < n - 1; ++j) {
                    tmp[j] = tmp[j - 1] ^ tmp[j];
                }
                if (tmp[n - 1] == x) {
                    ans = x;
                    goto ANS;
                }
            }
        }

        ANS:
        ans = a[n - 1];
        cout << ans << '\n';
    }

    return 0;
}
