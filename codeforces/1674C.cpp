// C. Infinite Replacement
//  Wrong answer on test 2

#include <iostream>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {

        string s;
        cin >> s;

        string t;
        cin >> t;

        long long ans = 1;

        if (t.find('a') != string::npos) {
            if (t.size() > 1) ans = -1;
        }
        else {
            // Editorial - https://codeforces.com/blog/entry/102482
            int n = s.size();
            ans = 2LL << (n - 1);
        }

        cout << ans << '\n';
    }

    return 0;
}
