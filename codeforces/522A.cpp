// A. Reposts

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


inline void toLower(string& s) {
    transform(s.begin(), s.end(), s.begin(), [](char c){
        return tolower(c);
    });
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<string, int> mp;

    int ans = 0;

    // Editorial - https://codeforces.com/blog/entry/16853

    mp["polycarp"] = 1;

    string first, tmp, last;
    int pos;
    for (int i = 0; i < n; ++i) {
        cin >> first >> tmp >> last;
        toLower(first);
        toLower(last);
        mp[first] = mp[last] + 1;
        ans = max(ans, mp[first]);
    }

    cout << ans << '\n';

    return 0;
}
