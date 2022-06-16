// A. Creep

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int a, b;
        cin >> a >> b;

        int aa = 0, bb = 1;
        if (a > b) {
            swap(a, b);
            swap(aa, bb);
        }

        int x = b / a;
        int rem = b % a;

        b -= rem;
        while (b > 0) {
            cout << aa;
            for (int i = 0; i < x; ++i, --b) cout << bb;
        }
        for (int i = 0; i < rem; ++i) cout << bb;
        cout << '\n';
    }

    return 0;
}
