// B. Minimal Cost

#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, u, v;
        cin >> n >> u >> v;

        vector<int> a(n);
        set<int> st;
        for (auto &el: a) {
            cin >> el;
            st.insert(el);
        }

        int ans = -1;

        if (st.size() != 1) {
            for (int i = 1; i < n; ++i) {
                if (abs(a[i] - a[i-1]) > 1) {
                    ans = 0;
                    break;
                }
            }
            if (ans == -1) {
                ans = min(u, v);
            }
        }

        else {
            ans = min(u + v, 2 * v);
        }

        cout << ans << endl;
    }

    return 0;
}
