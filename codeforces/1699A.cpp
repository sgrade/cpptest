// A. The Third Three Number Problem

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

        bool ans = n % 2 == 0 ? true : false;

        if (!ans) {
            cout << "-1\n";
            continue;
        }

        int a = 0, b = n / 2, c = n / 2;

        cout << a << ' ' << b << ' ' << c << '\n';
    }

    return 0;
}
