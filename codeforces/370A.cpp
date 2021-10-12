// A. Rook, Bishop and King

#include <iostream>

using namespace std;


int main() {

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int r = 0, b = 0, k = 0;

    if (r1 == r2 || c1 == c2) {
        r = 1;
    }
    else {
        r = 2;
    }

    // Editorial - https://codeforces.com/blog/entry/9866
    // Black bishop cannot reach white destination; same for white bishop and black dest
    if ((r1 + c1) % 2 != (r2 + c2) % 2) {
        b = 0;
    }
    else {
        // Left-right diagonal || right-left diagonal
        if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2) {
            b = 1;
        }
        else {
            b = 2;
        }
    }

    k = max(abs(r1 - r2), abs(c1 - c2));

    cout << r << ' ' << b << ' ' << k << '\n';

    return 0;
}
