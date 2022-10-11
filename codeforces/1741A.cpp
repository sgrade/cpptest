// A. Compare T-Shirt Sizes

#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string s1, s2;
        cin >> s1 >> s2;

        map<char, int> mp;
        mp['S'] = 0;
        mp['M'] = 1;
        mp['L'] = 2;

        int idx1 = mp[s1[s1.size() - 1]];
        int idx2 = mp[s2[s2.size() - 1]];
        
        char ans;

        if (s1[s1.size() - 1] == s2[s2.size() - 1]) {
            if (s1[s1.size() - 1] == 'S') {
                idx1 -= s1.size();
                idx2 -= s2.size();
            }
            else if (s1[s1.size() - 1] == 'L') {
                idx1 += s1.size();
                idx2 += s2.size();
            }
        }
        
        if (idx1 < idx2) {
            ans = '<';
        }
        else if (idx1 > idx2) {
            ans = '>';
        }
        else {
            ans = '=';
        }

        cout << ans << '\n';
    }


    return 0;
}
