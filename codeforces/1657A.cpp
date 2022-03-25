// A. Integer Moves

#include <iostream>
#include <math.h>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int x, y;
        cin >> x >> y;

        int ans = 2;

        if (x == 0 && y == 0) {
            ans = 0;
        }

        else {
            int d = x * x + y * y;
            
            // https://stackoverflow.com/questions/22239097/determining-if-square-root-is-an-integer
            int s = sqrt(d);
            if ((s * s) == d) {
                ans = 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
