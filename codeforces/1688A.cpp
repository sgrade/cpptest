// A. Cirno's Perfect Bitmasks Classroom
// Time limit exceeded on test 4

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int x;
        cin >> x;

        int y = 1;
        while (true) {
            if ((x & y) && (x ^ y)) {
                break;
            }
            ++y;
        }

        cout << y << '\n';
    }

    return 0;
}
