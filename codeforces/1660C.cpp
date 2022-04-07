// C. Get an Even String

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

        string s;
        cin >> s;

        int ans = 0;

        map<char, int> mp;
        map<char, int>::iterator it;
        int d, left;
        for (int i = 0; i < size(s); ++i) {
            
            it = mp.find(s[i]);
            if (it != end(mp)) {
                ans += mp.size() - 1;
                mp.erase(mp.begin(), mp.end());
            }

            else {
                mp[s[i]] = i;
            }
        }

        ans += mp.size();

        cout << ans << '\n';
    }

    return 0;
}
