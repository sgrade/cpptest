// A. Madoka and Math Dad

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int x = n / 3;
        int rem = n % 3;

        if (rem == 1) {
            cout << '1';
        }

        while (x--) {
            cout << '2' << '1';
        }

        if (rem == 2) {
            cout << '2';
        }

        cout << '\n';
    }

    return 0;
}
