// A. Food for Animals

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;

        x -= a;
        x = max(x, 0);
        y -= b;
        y = max(y, 0);

        bool ans = true;

        if (c < x + y) ans = false;

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
