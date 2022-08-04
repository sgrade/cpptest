// B. Permutation Chain

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

        cout << n << '\n';

        for (int i = 1; i <= n; ++i) {
            cout << i << ' ';
        }
        cout << '\n';

        int idx = 1;

        for (int i = 1; i < n; ++i) {

            for (int i = 1; i < idx + 1; ++i) {
                cout << i + 1 << ' ';
            }

            cout << 1 << ' ';

            for (int i = idx + 2; i <= n; ++i) {
                cout << i << ' ';
            }

            cout << endl;

            ++idx;
        }
    }

    return 0;
}
