// A. Shortest Path with Obstacle

#include <iostream>
#include <algorithm>

using namespace std;


int check(int a, int b, int f) {
    int out = 0;
    for (int i = 0; i < 2; ++i) {
        if (a < f && f < b) {
            out += 2;
            break;
        }
        swap(a, b);
    }
    return out;
}


int main() {

    int t;
    cin >> t;

    while (t--) {

        int xa, ya, xb, yb, xf, yf;
        cin >> xa >> ya;
        cin >> xb >> yb;
        cin >> xf >> yf;

        int ans = 0;

        ans += abs(xb - xa) + abs(yb - ya);
        
        if (xa == xf && xb == xf) {
            ans += check(ya, yb, yf);
        }
        if (ya == yf && yb == yf) {
            ans += check(xa, xb, xf);
        }

        cout << ans << endl;
    }

    return 0;
}
