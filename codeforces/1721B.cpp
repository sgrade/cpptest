// B. Deadly Laser

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m, r, c, d;
        cin >> n >> m >> r >> c >> d;

        // From 1,1 to the right - need top row
        bool top = r - d > 1 ? true : false;
        // Need bot row
        bool bot = r + d < n ? true : false;
        // Need left column
        bool left = c - d > 1 ? true : false;
        // Need right column
        bool right = c + d < m ? true : false;

        bool ans = false;

        if (top && right) {
            ans = true;
        }
        else if (left && bot) {
            ans = true;
        }

        cout << (ans ? (n - 1 + m - 1) : -1) << '\n';
    }

    return 0;
}
