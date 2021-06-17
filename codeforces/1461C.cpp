// C. Random Events

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for(auto &el: a) {
            cin >> el;
        }

        vector<pair<int, double>> rp(m);
        for (auto &el: rp) {
            cin >> el.first >> el.second;
        }

        // Editorial - https://codeforces.com/blog/entry/85491
        // Explanation - https://www.youtube.com/watch?v=LoQxDLzXJjs

        int last_not_sorted = -1;
        double ans = 1;

        for (int i = 0; i < n; ++i) {
            if (a[i] != i+1) {
                last_not_sorted = i + 1;
            }
        }
        
        if (last_not_sorted != -1) {
            for (int i = 0; i < m; ++i) {
                if (rp[i].first >= last_not_sorted) {
                    ans *= (1 - rp[i].second);
                }
            }
            ans = 1 - ans;
        }

        cout << ans << endl;
    }

    return 0;
}
