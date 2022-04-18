// C. Line Empire
// NOT FINISHED

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, a, b;
        cin >> n >> a >> b;

        vector<ll> x(n + 1), p(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            cin >> x[i];

            // partial sum (see the note below)
            p[i] = p[i-1] + x[i];
        }
        // Note: An alternative way to get p (from the Editorial)
        // partial_sum(x.begin(), x.end(), p.begin());

        ll ans = numeric_limits<ll>::max();
        // Move + Conquer
        ll mc;
        // Conquer
        ll c, p_diff, b_in_p_from_behind;

        for (int i = 1; i < n + 1; ++i) {

            // Move + conquer to the previous kingdom (new capital)
            mc = x[i-1] * (a + b);

            // Conquer from the prev kingdom (new capital) to the end
            // x left
            p_diff = b * (p[n] - p[i-1]);
            // part, that in p, but we don't need it as it is already included in mc
            b_in_p_from_behind = b * ( (n - i + 1) * x[i-1] );
            // Cost to conquer
            c = p_diff - b_in_p_from_behind;

            c += mc;

            ans = min(ans, c);
        }

        cout << ans << '\n';
    }

    return 0;
}
