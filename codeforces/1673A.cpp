// A. Subtle Substring Subtraction

#include <iostream>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        int n = s.size();

        int ans = 0;
        string winner;

        for (int i = 0; i < n; ++i) {
            ans += s[i] - 96;
        }

        if (n == 1) {
            winner = "Bob";
        }
        else {
            winner = "Alice";
        }

        if (n > 1 && n % 2 != 0) {
            int b;
            if (s[0] < s[n-1]) b = s[0];
            else b = s[n-1];
            b -= 96;
            ans -= b * 2;
        }

        cout << winner << ' ' << ans << '\n';
    }

    return 0;
}
