// B. DIV + MOD

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int l, r, a;
        cin >> l >> r >> a;

        int x = r / a + r % a;

        // Editorial - https://codeforces.com/blog/entry/100712
        int m = r / a * a - 1;

        if (m >= l) {
            x = max (m / a + m % a, x);
        }

        cout << x << '\n';
    }

    return 0;
}
