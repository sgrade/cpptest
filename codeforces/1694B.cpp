// B. Paranoid String

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

        long long ans = n;

        int prev = s[0];
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] != s[i]) {
                ans += i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
