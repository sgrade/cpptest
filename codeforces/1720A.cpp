// A. Burenka Plays with Fractions

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        int ans = 0;

        if (b == d) {
            if (a != c) {
                if (a < c) {
                    swap(a, c);
                }
                if (a % c == 0) {
                    ans = 1;
                }
                else {
                    ans = 2;
                }
            }
        }

        else {
            long long x = b * d;
            a *= d;
            c *= b;
            
            if (a != c) {
                if (a == 0 || c == 0) {
                    ans = 1;
                }
                else {
                    if (a < c) {
                        swap(a, c);
                    }
                    if (a % c == 0) {
                        ans = 1;
                    }
                    else {
                        ans = 2;
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
