// A. King Escape

#include <iostream>

using namespace std;


int main() {

    int n;
    cin >> n;

    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    bool ans = false;

    // Editorial - https://codeforces.com/blog/entry/62287
    // Idea for implementation - https://codeforces.com/contest/1033/submission/43952286

    bool king_top = bx > ax ? true : false;
    bool target_top = cx > ax ? true : false;

    bool king_left = by < ay ? true : false;
    bool target_left = cy < ay ? true : false;

    if (king_top == target_top && king_left == target_left) {
        ans = true;
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
