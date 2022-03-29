// A. Marin and Photoshoot

#include <iostream>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        int ans = 0;

        int ones = 2;

        // Idea - https://codeforces.com/contest/1658/submission/151108106
        for (int i = 0; i < n; ++i) {

            if (s[i] == '1') {
                ++ones;
            }

            else {
                if (ones == 0) {
                    ans += 2;
                }
                else if ( ones == 1) {
                    ++ ans;
                }
                ones = 0;
            }
            
        }

        cout << ans << '\n';
    }

    return 0;
}
