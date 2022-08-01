// B. Remove Prefix

#include <iostream>
#include <algorithm>
#include <set>
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

        set<int> st;
        int tmp;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int i = n - 1;
        for (; i > -1; --i) {
            if (st.find(a[i]) != st.end()) {
                break;
            }
            st.emplace(a[i]);
        }
        int ans = i + 1;
        
        cout << ans << '\n';
    }

    return 0;
}
