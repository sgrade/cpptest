// C. Helping the Nature

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

        vector<long long> a(n);
        for (long long &el: a) cin >> el;

        // Short editorial - https://codeforces.com/blog/entry/103978
        // Explanation - https://www.youtube.com/watch?v=A5TVN5ubrqY

        long long ans = 0;

        long long mn = a[0], ops = 0;
        for (int i = 1; i < n; ++i) {
            a[i] -= ops;
            mn = min(mn, a[i]);
            ops += abs(a[i] - mn);
            a[i] = mn;
        }
        ans += ops;

        mn = a[n - 1], ops = 0;
        for (int i = n - 2; i >= 0; --i) {
            a[i] -= ops;
            ops += a[i] - mn;
            a[i] = mn;
        }

        ans += ops + abs(a[0]);

        cout << ans << '\n';
    }

    return 0;
}
