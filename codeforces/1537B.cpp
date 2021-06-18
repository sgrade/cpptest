// B. Bad Boy

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        ll n, m, i, j;
        cin >> n >> m >> i >> j;

        vector<vector<ll>> v = {
            {1, 1}, 
            {1, m}, 
            {n, 1}, 
            {n, m}
        };

        vector<vector<int>> ans;
        int d;
        for (int k = 0; k < 4; ++k) {
            d = abs(v[k][0] - i) + abs(v[k][1] - j);
            vector<int> tmp = {d, k};
            ans.push_back(tmp);
        }
        sort(begin(ans), end(ans));

        int idx1, idx2;
        idx1 = ans[3][1];
        if (idx1 == 0) {
            idx2 = 3;
        }
        else if (idx1 == 1) {
            idx2 = 2;
        }
        else if (idx1 == 2) {
            idx2 = 1;
        }
        else {
            idx2 = 0;
        }


        cout << v[idx1][0] << ' ' << v[idx1][1] << ' ';
        cout << v[idx2][0] << ' ' << v[idx2][1];
        cout << endl;
    }

    return 0;
}
