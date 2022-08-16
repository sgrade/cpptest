// A. Chip Game

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        bool ans = false;

        if (m % 2 == 0) {
            if (n % 2 == 0) {
                ans = true;
            }
        }

        else {
            if (n % 2 != 0) {
                ans = true;
            }
        }

        cout << (ans ? "Tonya\n" : "Burenka\n");
    }

    return 0;
}
