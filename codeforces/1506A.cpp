// A. Strange Table

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ull = unsigned long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        ull n, m, x;
        cin >> n >> m >> x;

        ull row, column;
        column = (x + n - 1) / n;
        row = x - (column - 1) * n;

        ull y;
        y = (row - 1) * m + column;

        cout << y << endl;
    }

    return 0;
}
