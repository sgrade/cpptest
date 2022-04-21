// E. 2-Letter Strings

#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        ll ans = 0;

        map<char, pair<int, int>> mp;
        string s;

        map<string, int> duplicates;

        for (int i = 0; i < n; ++i) {
            cin >> s;

            ans += mp[s[0]].first;
            ans += mp[s[1]].second;

            ++mp[s[0]].first;
            ++mp[s[1]].second;

            if (duplicates.find(s) != duplicates.end()) {
                ans -= duplicates[s] * 2;
            }
            ++duplicates[s];
        }

        cout << ans << '\n';
    }

    return 0;
}
