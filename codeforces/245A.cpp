// A. System Administrator

#include <iostream>

using namespace std;


int main() {

    int n;
    cin >> n;

    int t, x, y;
    int a_reached = 0, a_total = 0, b_reached = 0, b_total = 0;

    for (int i = 0; i < n; ++i) {
        cin >> t >> x >> y;
        if (t == 1) {
            a_reached += x;
            a_total += x + y;
        }
        else {
            b_reached += x;
            b_total += x + y;
        }
    }

    cout << (a_reached * 2 >= a_total ? "LIVE" : "DEAD") << endl;
    cout << (b_reached * 2 >= b_total ? "LIVE" : "DEAD") << endl;

    return 0;
}
