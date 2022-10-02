// C. Phase Shift
// NOT FINISHED (cannot figure out the second test)

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::string alpha = "abcdefghijklmnopqrstuvwxyz";

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        string ans;

        int idx = 0;
        map<char, char> mp;
        vector<bool> chosen(26);

        int i = 0;
        for (; i < n; ++i) {
            if (idx >= 26) 
                break;
            
            if (mp.find(s[i]) == mp.end()) {
                int temp_idx = idx;
                while (s[i] == alpha[temp_idx] || chosen[temp_idx]) {
                    ++temp_idx;
                }
                mp[s[i]] = alpha[temp_idx];
                chosen[temp_idx] = true;
                if (temp_idx == idx) {
                    ++idx;
                }
            }
            ans += mp[s[i]];
        }

        for (; i < n; ++i) {
            ans += mp[s[i]];
        }

        cout << ans << '\n';
    }

    return 0;
}
