// A. Broken Keyboard

#include <iostream>
#include <string>
#include <set>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        
        string s;
        cin >> s;

        int n = s.size();

        set<char> ans;

        if (n == 1) {
            cout << s;
            cout << '\n';
            continue;
        }

        if (s[0] != s[1]) {
            ans.emplace(s[0]);
            if (n == 2) {
                ans.emplace(s[1]);
            }
        }

        if (n > 2 && s[n - 2] != s[n - 1]) {
            ans.emplace(s[n - 1]);
        }
        
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
                ans.emplace(s[i]);
            }
            if (s[i - 1] == s[i]) {
                int count = 2;
                int j = i + 1;
                while (s[j] == s[i]) {
                    ++count;
                    ++j;
                }
                if (count % 2 != 0) {
                    ans.emplace(s[i]);
                }
                i = j - 1;
            }
        }

        for (const char &c: ans) {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}
