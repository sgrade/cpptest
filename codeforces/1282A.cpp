// A. Temporarily unavailable

#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int a, b, c, r;
        cin >> a >> b >> c >> r;

        if (a > b) {
            swap(a, b);
        }

        int ans = b - a;

        int c_begin = c-r < a ? a : c-r;
        int c_end = c+r > b ? b : c+r;
        ans -= max(0, c_end - c_begin);

        cout << ans << endl;
    }


    return 0;
}
