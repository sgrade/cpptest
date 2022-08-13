// B. Rooms and Staircases

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

        int left = -1, right = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                left = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                right = i;
                break;
            }
        }

        int ans = n;

        if (right != -1) {
            ans = max(ans, 2 * (right + 1));
        }
        if (left != -1) {
            ans = max(ans, 2 * (n - left));
        }

        cout << ans << '\n';
    }

    return 0;
}
