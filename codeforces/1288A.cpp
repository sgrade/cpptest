// A. Deadline

#include <iostream>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, d;
        cin >> n >> d;

        bool ans = false;

        int l = 0, r = n, x, days;

        // binary search
        // Idea - https://codeforces.com/contest/1288/submission/69447202
        while (l < r) {

            x = (l + r) / 2;
            days = x + d / (x + 1);
            if (d % (x + 1) != 0) {
                ++days;
            }

            if (days > n) {
                l = x + 1;
            }
            else {
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
