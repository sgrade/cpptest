// A. A Variety of Operations

#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int c, d;
        cin >> c >> d;

        int ans;

        if (abs(c - d) % 2 != 0) {
            ans = -1;
        }

        else {
            if (c == d) {
                if (c == 0) {
                    ans = 0;
                }
                else {
                    ans = 1;
                }
            }
            else {
                ans = 2;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
