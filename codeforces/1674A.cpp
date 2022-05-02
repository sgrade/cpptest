// A. Number Transformation

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int x, y;
        cin >> x >> y;

        int a = 0, b = 0;

        if (x <= y && y % x == 0) {
            b = y / x;
            a = 1;
        }

        cout << a << ' ' << b << "\n";
    }

    return 0;
}
