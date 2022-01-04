// A. Stable Arrangement of Rooks

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        if (k > (n + 2 - 1) / 2) {
            cout << "-1" << endl;
            continue;
        }

        int x = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (k > 0 && i == x && j == x) {
                    cout << 'R';
                }
                else {
                    cout << '.';
                }
            }
            cout << '\n';

            if (i % 2 != 0) {
                x += 2;
                --k;
            }
        }
    }

    return 0;
}
