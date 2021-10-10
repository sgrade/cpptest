// B. Fridge Lockers

#include <iostream>

using namespace std;


int main () {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        int tmp;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ans += tmp * 2;
        }

        if (n < 3 || m < n) {
            ans = -1;
        }

        cout << ans << '\n';
        if (ans != -1) {
            for(int i = 1; i <= n - 1; i++)
                cout << i << ' ' << i + 1 << '\n';
            cout << 1 << ' ' << n << '\n';
        }
    }

    return 0;
}
