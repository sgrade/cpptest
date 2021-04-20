// A. Game Outcome

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<vector<int>> v(n);
    vector<int> tmp(n);

    for (auto &el: v) {
        for (auto &x: tmp) {
            cin >> x;
        }
        el = tmp;
    }

    int ans = 0;

    int row, col;
    for (int i = 0; i < n; ++i) {
        row = accumulate(v[i].begin(), v[i].end(), 0);

        for (int j = 0; j < n; ++j) {
            col = 0;
            for (int k = 0; k < n; ++k) {
                col += v[k][j];
            }
            if (col > row) {
                ++ans;
            }
        }
    }
 
    cout << ans << endl;

    return 0;
}
