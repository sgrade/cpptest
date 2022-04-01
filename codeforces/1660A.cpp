// A. Vasya and Coins

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int a, b;
        cin >> a >> b;

        int ans;

        if (a == 0) {
            ans = 1;
        }
        else {
            ans = b * 2 + a + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
