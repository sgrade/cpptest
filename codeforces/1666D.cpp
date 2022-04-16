// D. Deletive Editing

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {

        string s, t;
        cin >> s >> t;

        int ss = s.size(), tt = t.size();

        bool ans = true; 
        
        int prev = ss;
        map<char, int> mp;
        
        size_t idx, last;
        
        for (int i = tt - 1; i > -1; --i) {
            
            if (mp.find(t[i]) != mp.end()) last = mp[t[i]];
            else last = ss;

            idx = s.substr(0, last).find_last_of(t[i]);

            if (idx == string::npos || idx > prev) {
                ans = false;
                break;
            }
            
            prev = idx;
            mp[t[i]] = idx;
        }

        cout << (ans ? "YES\n": "NO\n");
    }

    return 0;
}
