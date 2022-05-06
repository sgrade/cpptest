// B. Dorms War

#include <iostream>
#include <vector>
#include <set>
#include <string>
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

        int k;
        cin >> k;

        char ch;
        set<char> st;
        for (int i = 0; i < k; ++i) {
            cin >> ch;
            st.insert(ch);
        }

        int ans = 0, cur_ans = 0;

        int i = 0;
        int prev = 0;
        
        while (true) {
            
            if (i > n - 1) break;

            if (st.find(s[i]) == st.end()) {
                ++i;
            }
            else {
                cur_ans = i - prev;
                ans = max(cur_ans, ans);
                prev = i;
                ++i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
