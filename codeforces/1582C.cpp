// C. Grandma Capa Knits a Scarf

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <limits>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        // Editorial - https://codeforces.com/blog/entry/96267
        set<char> st;

        int ans = numeric_limits<int>::max();
        
        for (auto &ch: s) {

            // Already checked char
            if (st.find(ch) != st.end()) {
                continue;
            }
            st.insert(ch);

            int l = 0, r = n-1;
            int cur_ans = 0;
            
            while (l < r) {
                if (s[l] != s[r]) {
                    if (s[l] != ch && s[r] != ch) {
                        cur_ans = numeric_limits<int>::max();
                        break;
                    }
                    if (s[l] == ch) {
                        ++l;
                    }
                    else {
                        --r;
                    }
                    ++cur_ans;
                }
                else {
                    ++l;
                    --r;
                }
            }

            ans = min(ans, cur_ans);
            if (ans == 0) {
                break;
            }
        }

        if (ans > n) {
            ans = -1;
        }

        cout << ans << endl;
    }

    return 0;
}
