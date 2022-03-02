// A. ConneR and the A.R.C. Markland-N

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, s, k;
        cin >> n >> s >> k;

        set<int> a;
        int tmp;
        for (int i = 0; i < k; ++i) {
            cin >> tmp;
            a.insert(tmp);
        }

        ++n;
        int ans = 0;

        // Idea - https://codeforces.com/contest/1293/submission/69125876
        while (true) {
            if (s - ans > 0 && a.find(s - ans) == end(a)) {
                break;
            }
            if (s + ans < n && a.find(s + ans) == end(a)) {
                break;
            }
            ++ans;
        }

        cout << ans << '\n';
    }

    return 0;
}
