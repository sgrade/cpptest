// A. Div. 7

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

        int ans = 0;

        if (n % 7 == 0) {
            ans = n;
        }

        else {
            int rem = 0;
            while (n % 10 != 0) {
                --n;
                if (n % 7 == 0) {
                    ans = n;
                    break;
                }
                ++rem;
            }
            if (ans == 0) {
                n += rem == 0 ? 1 : rem;
                while (n % 10 != 0) {
                    ++n;
                    if (n % 7 == 0) {
                        ans = n;
                        break;
                    }
                }
            }
        }

        cout << ans << '\n';
    }



    return 0;
}
