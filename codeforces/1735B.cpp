// B. Tea with Tangerines

#include <iostream>
#include <vector>
#include <algorithm>

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

        sort(a.begin(), a.end());
        
        int cur_min = a[0], cur_max = a[0] + a[0] - 1;

        long long ans = 0;

        int cur_ans, rem, rem_per_min;
        for (int i = 1; i < n; ++i) {
            if (a[i] < cur_max)
                continue;

            cur_ans = (a[i] + cur_max - 1) / cur_max;
            rem = a[i] - cur_min * cur_ans;
            rem_per_min = (rem + cur_ans - 1) / cur_ans;
            if (cur_min + rem_per_min > cur_max) {
                cur_ans = (a[i] + cur_min - 1) / cur_min;
                cur_min = a[i] / cur_ans + (a[i] % cur_ans) / cur_ans;
                cur_max = cur_min + cur_min;
            }
            ans += cur_ans - 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
