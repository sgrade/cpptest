// B. Plus and Multiply

#include <iostream>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, a, b;
        cin >> n >> a >> b;

        bool ans = false;

        if ((n - 1) % b == 0) {
            ans = true;
        }

        else if (a > 1) {
            long long x = 1LL;
            long long rem;
            while (x <= n) {
                rem = n - x;
                if (rem % b == 0) {
                    ans = true;
                    break;
                }
                x *= a;
            }
        }

        cout << (ans ? "Yes" : "No") << endl;

    }

    return 0;
}
