// A. Exciting Bets

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        ll a, b;
        cin >> a >> b;

        ll excitement = llabs(a - b);

        ll steps;
        if (excitement == 0) {
            steps = 0;
        }
        else {
            ll reminder = a % excitement;
            steps = min(reminder, excitement - reminder);
        }

        cout << excitement << ' ' << steps << endl;

    }

    return 0;
}
