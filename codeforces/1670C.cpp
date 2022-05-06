// C. Where is the Pizza?
// NOT FINISHED

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n), b(n), d(n);
        for (int &el: a) cin >> el;
        for (int &el: b) cin >> el;
        for (int &el: d) cin >> el;

        vector<bool> taken_a(n+1), taken_b(n+1);

        ll ans = 1LL;

        if (n > 1) {

            for (int i = 0; i < n; ++i) {
                if (d[i] != 0) {
                    if (d[i] == a[i]) taken_a[d[i]] = true;
                    else taken_b[d[i]] = true;
                }
            }

            for (int i = 0; i < n; ++i) {

                if (d[i] == 0) {
                    
                    bool flag = false;
                    
                    if (taken_a[a[i]] || taken_b[b[i]]) {
                        flag = true;
                        continue;
                    }

                    taken_a[a[i]] = true;
                    taken_b[b[i]] = true;
                    
                    if (flag && a[i] != b[i]) {
                        ans *= 2;
                        ans %= MOD;
                    }
                }
            }

        }

        cout << ans << '\n';
    }

    return 0;
}
