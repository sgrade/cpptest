// B. Morning Jogging
// Wrong answer on pretest 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<vector<int>> v(n);
        for (int i = 0; i < n; ++i) {
            vector<int> v_tmp(m);
            for (auto &el: v_tmp) {
                cin >> el;
            }
            sort(v_tmp.begin(), v_tmp.end());
            v[i] = v_tmp;
        }

        vector<vector<int>> ans(n);

        int shift = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> v_tmp;
            for (int j = shift; j < m; ++j) {
                ans[i].push_back(v[i][j]);
            }
            for (int j = 0; j < shift; ++j) {
                ans[i].push_back(v[i][j]);
            }
            ++shift;
        }
        
        for (auto &el_v: ans) {
            for (auto &el: el_v) {
                cout << el << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
