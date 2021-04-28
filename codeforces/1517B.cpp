// B. Morning Jogging

#include <iostream>
#include <set>
#include <map>
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

        // Input
        vector<map<int, int>> inp(n);
        // Sorted input data
        multiset<vector<int>> mins;

        int tmp;
        for (int i = 0; i < n; ++i) {
            map<int, int> mp_i;
            vector<int> v(2);
            for (int j = 0; j < m; ++j) {
                cin >> tmp;
                ++mp_i[tmp];
                v = {tmp, i};
                mins.insert(v);
            }
            inp[i] = mp_i;
        }

        // Placeholder for the answer
        vector<vector<int>> ans(n, vector<int>(m));
        
        multiset<vector<int>>::iterator mins_it = mins.begin();
        int mn, i;
        for (int j = 0; j < m; ++j) {
            mn = (*mins_it)[0];
            i = (*mins_it)[1];
            ans[i][j] = mn;
            ++mins_it;
            --inp[i][mn];
        }

        map<int, int>::iterator it;
        for (int i = 0; i < n; ++i) {
            it = inp[i].begin();
            for (int j = 0; j < m; ++j) {
                if (ans[i][j] == 0) {
                    while (it->second == 0) {
                        ++it;
                    }
                    ans[i][j] = it->first;
                    --it->second;
                }
            }
        }

        for (auto &i: ans) {
            for (auto &j: i) {
                cout << j << ' ';
            }
            cout << endl;
        }
        
    }

    return 0;
}
