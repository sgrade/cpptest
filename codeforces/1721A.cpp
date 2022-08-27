// A. Image

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

        string s1, s2;
        cin >> s1 >> s2;

        set<char> chars;
        chars.emplace(s1[0]);
        chars.emplace(s1[1]);
        chars.emplace(s2[0]);
        chars.emplace(s2[1]);

        int ans = chars.size() - 1;

        cout << ans << '\n';
    }

    return 0;
}
