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

        vector<int> max_idx(n);
        max_idx[0] = indexes[a[0]];
        for (int i = 1; i < n; ++i) {
            max_idx[i] = max(max_idx[i - 1], indexes[a[i]]);
        }

        int ans = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                ans = min(count_so_far[max_idx[i]], max_idx[i]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
