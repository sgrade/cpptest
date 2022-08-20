// A. Crossmarket

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        if (n == 1 && m == 1) {
            cout << 0 << '\n';
            continue;
        }

        cout << (n - 1 + m - 1) + (min(n, m) - 1) + 1 << '\n';
    }

    return 0;
}
