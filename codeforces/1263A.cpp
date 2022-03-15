// A. Sweet Problem

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

        vector<int> rgb(3);
        for (int &el: rgb) {
            cin >> el;
        }
        sort(begin(rgb), end(rgb));

        int ans = 0;

        int cur = min(rgb[0], rgb[2]-rgb[1]);
        rgb[0] -= cur;
        rgb[2] -= cur;
        ans += cur;

        cur = rgb[0] / 2;
        rgb[0] -= cur * 2;
        rgb[1] -= cur;
        rgb[2] -= cur;
        ans += cur * 2;

        sort(begin(rgb), end(rgb));

        ans += min(rgb[1], rgb[2]);

        cout << ans << '\n';
    }

    return 0;
}
