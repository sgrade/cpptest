// B. Haunted House

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // leading_zero_indexes
        stack<int> st;
        st.emplace(0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0')
                st.emplace(i);
        }
        
        int trailing_zeroes = 0, leading_zeroes = 0;
        int need_trailing_zeroes = 0;
        long long ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            trailing_zeroes += s[i] == '0';
            need_trailing_zeroes = n - i - trailing_zeroes;
            if (need_trailing_zeroes == 0) {
                cout << 0 << ' ';
                continue;
            }
            while (!st.empty() && st.top() >= i)
                st.pop();
            leading_zeroes = st.size() - 1;
            if (leading_zeroes < need_trailing_zeroes) {
                cout << -1 << ' ';
                continue;
            }
            int idx = st.top();
            ans += i - idx;
            swap(s[i], s[idx]);
            st.pop();
            ++trailing_zeroes;
            cout << ans << ' ';
        }
        cout << "\n";
    }

    return 0;
}
