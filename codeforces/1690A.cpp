// A. Print a Pedestal (Codeforces logo?)

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

        int x = (n - 6) / 3;
        int rem = (n - 6) % 3;

        int h2, h1, h3;

        h2 = x + 2;
        if (rem == 2) ++h2;

        h1 = x + 3;
        if (rem == 1 || rem == 2) ++h1;

        h3 = x + 1;

        cout << h2 << ' ' << h1 << ' ' << h3 << '\n';
    }

    return 0;
}
