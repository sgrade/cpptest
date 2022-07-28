// D. Double Strings

#include <iostream>
#include <string>
#include <unordered_set>
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

        string s;
        vector<string> a(n);
        unordered_set<string> st;

        for (int i = 0; i < n; ++i) {
            cin >> s;
            a[i] = s;
            st.emplace(s);
        }

        string ans;

        string sj, sk;
        for (int i = 0; i < n; ++i) {
            // Editorial - https://codeforces.com/blog/entry/104786
            for (int len = 1; len < a[i].size(); ++len) {
                sj = a[i].substr(0, len);
                sk = a[i].substr(len);
                if (st.count(sj) && st.count(sk)) {
                    ans += '1';
                    break;
                }
            }
            if (ans.size() == i) {
                ans += '0';
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
