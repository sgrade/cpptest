// A. Tokitsukaze and All Zero Sequence

#include <iostream>
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

        int tmp;
        set<int> st;
        int zeroes = 0;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            st.insert(tmp);
            if (tmp == 0) ++zeroes;
        }

        int ans;

        if (zeroes > 0) {
            ans = n - zeroes;
        }

        else {
            if (st.size() == n) {
                ans = n + 1;
            }

            else {
                ans = n;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
