// A. Traveling Salesman Problem

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

        int x, y;
        int minx = 0, miny = 0, maxx = 0, maxy = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            minx = min(x, minx);
            maxx = max(x, maxx);
            miny = min(y, miny);
            maxy = max(y, maxy);
        }

        int ans = 0;

        ans = (abs(minx) + abs(maxx)) * 2 + (abs(miny) + abs(maxy)) * 2;

        cout << ans << '\n';
    }

    return 0;
}
