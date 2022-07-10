// C. Train and Queries

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        unordered_map<int, pair<int, int>> u;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (u.find(tmp) == u.end()){
                u[tmp] = pair<int, int>(i, i);
            }
            else {
                u[tmp].second = i;
            }
        }

        int a, b;
        vector<bool> ans(k);
        for (int i = 0; i < k; ++i) {
            cin >> a >> b;
            if (u.find(a) != u.end() && u.find(b) != u.end()) {
                if (u[a].first <= u[b].second) {
                    ans[i] = true;
                }
            }
        }

        for (const bool &el: ans) {
            cout << (el ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
