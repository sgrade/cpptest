// C. Minimize Distance

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> x(n + 1);
        for (int i = 1; i < n + 1; ++i) cin >> x[i];

        sort(x.begin(), x.end());

        int mid = distance(x.begin(), find(x.begin(), x.end(), 0));

        ll ans = 0;

        int cur; 

        // Idea to iterate from the end to mid is from - https://codeforces.com/contest/1585/submission/138889405
        
        cur = n;
        while (cur > mid) {
            ans += x[cur];
            cur = max(cur - k, mid);
        }
        if (ans > 0) ans *= 2;

        ll cur_ans = 0;
        cur = 0;
        while (cur < mid) {
            cur_ans += abs(x[cur]);
            cur = min(cur + k, mid);
        }
        if (cur_ans > 0) {
            cur_ans *= 2;
        }

        ans += cur_ans;
        ans -= (max(abs(x[0]), x[n]));

        cout << ans << '\n';
    }

    return 0;
}
