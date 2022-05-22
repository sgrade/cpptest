// A. Palindromic Indices

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

        int i = n / 2;
        char mid = s[i];

        if (n % 2 != 0) {
            ++ans;
        }
        else {
            ans += 2;
        }

        ++i;
        while (i < n) {
            if (s[i] == mid) {
                ans += 2;
            }
            else {
                break;
            }
            ++i;
        }

        cout << ans << '\n';
    }

    return 0;
}
