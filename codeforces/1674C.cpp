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

        int ans = 1;

        if (t.find('a') != string::npos) {
            if (t.size() > 1) ans = -1;
        }
        else {
            ans += s.size();
            int n = s.size() - 1;
            while (n > 0) {
                ans += n;
                --n;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
