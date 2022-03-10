// B. Anti-Fibonacci Permutation

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) {

            a[0] = i + 1;

            int k = n;

            for (int j = 1; j < n; --k) {

                if (a[0] == k) {
                    continue;
                }
                a[j] = k;
                ++j;
            }

            for (int &el: a) {
                cout << el << ' ';
            }
            cout << '\n';

        }

    }

    return 0;
}
