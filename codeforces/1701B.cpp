// B. Permutation

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        cout << 2 << '\n';

        set<int> st;
        for (int i = 1; i <= n; ++i) {
            st.insert(i);
        }

        int i = 0;
        vector<int> ans(n);

        set<int>::iterator it;
        int tmp = 1;
        while (!st.empty()) {
            it = st.find(tmp * 2);
            if (it == st.end()) {
                ans[i] = tmp;
                st.erase(tmp);
                tmp = *st.begin();
            }
            else {
                ans[i] = tmp;
                st.erase(tmp);
                tmp = *it;
            }
            ++i;
        }

        for (int &el: ans) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}
