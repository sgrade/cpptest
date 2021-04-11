// A. Array and Peaks

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        bool ans = false;

        vector<int> p(n, -1);

        if (k == 0) {
            ans = true;
            for (int i = 0; i < n; ++i) {
                p[i] = i + 1;
            }
        }
        else if (2 * k + 1 <= n){
            ans = true;
            int rem = n - (2 * k);

            int i = 0;

            while (rem--){
                p[i] = i + 1;
                ++i;
            }

            while(k--) {
                p[i] = i + 2;
                p[i+1] = i + 1;
                i = i + 2;
            }
        }

        if (!ans) {
            cout << "-1\n";
        }
        else {
            for (auto &el: p) {
                cout << el << ' ';
            }
            cout << endl;
        }

    }

    return 0;
}
