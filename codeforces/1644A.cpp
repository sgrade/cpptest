// A. Doors and Keys

#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        bool ans = true;

        map<char, int> mp;
        char key;
        for (auto &ch: s) {
            if (isupper(ch)) {
                key = tolower(ch);
                if (mp.find(key) == end(mp)) {
                    ans = false;
                    break;
                }
                else {
                    --mp[key];
                }
            }
            
            else {
                ++mp[ch];
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
