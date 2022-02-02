// B. Roof Construction

#include <iostream>
#include <math.h>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/99442

        // find most significant bit - https://www.geeksforgeeks.org/find-significant-set-bit-number/
        int k = (int)(log2(n - 1));
        int x = 1 << k;

        for (int i = x - 1; i > -1; --i) {
            cout << i << ' ';
        }
        for (int i = x; i < n; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}
