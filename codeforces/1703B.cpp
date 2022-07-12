// B. ICPC Balloons

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

        string s;
        cin >> s;

        int ans = 0;

        set<char> st;

        for (int i = 0; i < n; ++i) {
            if (st.find(s[i]) == st.end()) {
                ans += 2;
                st.emplace(s[i]);
            }
            else ++ans;
        }

        cout << ans << '\n';
    }

    return 0;
}
