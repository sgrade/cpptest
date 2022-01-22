// A. Download More RAM

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<vector<int>> ab(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            cin >> ab[i][0];
        }
        for (int i = 0; i < n; ++i) {
            cin >> ab[i][1];
        }

        sort(begin(ab), end(ab));

        for (int i = 0; i < n; ++i) {
            if (ab[i][0] <= k) {
                k += ab[i][1];
            }
            else {
                break;
            }
        }

        cout << k << endl;
    }

    return 0;
}
