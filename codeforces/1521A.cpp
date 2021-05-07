// A. Nastia and nearly Good Numbers

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ull = unsigned long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        ull a, b;
        cin >> a >> b;

        bool ans = true;
        ull x, y, z;

        if (b == 1) {
            ans = false;
        }

        else {
            z = a * b;
            if (b == 2 || a == 1) {
                z *= 2;
            }
            x = z - a;
            y = z - x;
        }

        cout << (ans ? "YES" : "NO") << endl;
        if (ans) {
            cout << x << ' ' << y << ' ' << z << endl;
        }
    }

    return 0;
}
