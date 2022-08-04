// A. 2-3 Moves

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int ans;
        if (n == 1) {
            ans = 2;
        }
        else {
            ans = n / 3;
            if (n % 3 != 0) {
                ++ans;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
