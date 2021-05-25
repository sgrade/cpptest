// A. And Then There Were K

#include <iostream>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        // Source - https://www.geeksforgeeks.org/highest-power-2-less-equal-given-number/
        int highest_power_of_two = 1;
        for (int i = 0; i < 31; ++i) {
            int cur = 1 << i;
            if (cur > n) {
                break;
            }
            highest_power_of_two = cur;
        }

        cout << highest_power_of_two - 1 << endl;

    }

    return 0;
}
