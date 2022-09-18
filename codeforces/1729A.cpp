// A. Two Elevators

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int d = abs(b - c) + c;

        if (a < d) {
            cout << "1\n";
        }
        else if (a > d) {
            cout << "2\n";
        }
        else {
            cout << "3\n";
        }
    }

    return 0;
}
