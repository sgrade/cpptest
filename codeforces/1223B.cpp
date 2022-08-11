// B. Strings Equalization

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {
        string s, t;
        cin >> s >> t;

        // Editorial - https://codeforces.com/blog/entry/70358

        unordered_set<char> st;
        for (int i = 0; i < s.size(); ++i) {
            st.emplace(s[i]);
        }

        bool ans = false;
        for (int i = 0; i < t.size(); ++i) {
            if (st.find(t[i]) != st.end()) {
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
