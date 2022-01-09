// C. Paint the Array

#include <iostream>
#include <vector>
#include <numeric>

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

        vector<ll> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        // Editorial - https://codeforces.com/blog/entry/97927
        // Ideas from https://codeforces.com/contest/1618/submission/139228723

        // GCDs
        vector<ll> g = {a[0], a[1]};

        for (int i = 2; i < n; ++i) {
            g[i % 2] = gcd(g[i % 2], a[i]);
        }

        ll ans = 0;

        if (!(g[0] == 1 && g[1] == 1)) {
            
            for (int i = 0; i < 2; ++i) {
                ans = g[i];
                
                vector<int> color(n);
                for (int j = 0; j < n; ++j) {
                    color[j] = a[j] % ans == 0 ? 1 : 0;
                }

                for (int j = 1; j < n; ++j) {
                    if (color[j] == color[j-1]) {
                        ans = 0;
                        break;
                    }
                }

                if (ans != 0) {
                    break;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
