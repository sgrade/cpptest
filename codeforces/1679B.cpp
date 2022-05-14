// B. Stone Age Problem

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }
    
    ll ans = accumulate(a.begin(), a.end(), 0LL);

    int t, ii, x, type_2_x;
    bool type_2 = false;
    unordered_set<int> st;

    for (int i = 0; i < q; ++i) {

        cin >> t;

        if (t == 2) {
            type_2 = true;
            cin >> x;
            st.clear();
            type_2_x = x;
            ans = 1LL * x * n;
        }

        // t == 1
        else {
            cin >> ii >> x;
            if (type_2 && st.find(ii) == st.end()) {
                ans -= type_2_x;
            }
            else {
                ans -= a[ii];
            }
            st.insert(ii);
            a[ii] = x;
            ans += x;
        }

        cout << ans << '\n';
    }

    return 0;
}
