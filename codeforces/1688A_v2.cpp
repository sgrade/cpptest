// A. Cirno's Perfect Bitmasks Classroom

#include <iostream>


using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int x;
        cin >> x;

        // Idea - https://codeforces.com/contest/1688/submission/159352249

        int y = x & -x;

        if (y == x) {
            y++;
        }

        if (x == 1) {
            y = 3;
        }

        cout << y << '\n';
    }

    return 0;
}
