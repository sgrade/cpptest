// C. Sort Zero
// Doesn't work

#include <iostream>
#include <vector>
#include <limits>
#include <set>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n), indexes(n + 1), count_so_far(n);
        set<int> st;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];

            // Idea from - https://codeforces.com/contest/1712/submission/168111127
            indexes[a[i]] = i;

            st.emplace(a[i]);
            count_so_far[i] = st.size();
        }

        int ans = 0;

        int idx = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i] + 1) {
                idx = max(idx, indexes[a[i]]);
                ans = max(ans, count_so_far[idx]);
                if (idx < n - 1 && a[idx] > a[idx + 1]) {
                    ++idx;
                }
                ans = min(ans, idx);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
