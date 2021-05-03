// C. Phoenix and Towers

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>
#include <set>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m, x;
        cin >> n >> m >> x;

        int tmp;

        // <height, count_of_such_heights>
        map<int, int, greater<int>> mp;
        // original indexes of the heights
        multimap<int, int> original_indexes;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++mp[tmp];
            original_indexes.insert(pair<int, int>(tmp, i));
        }

        bool ans = true;
        vector<int> output(n);

        if (m > 1) {
            // pair<int, int>: first is sum, second is index in heights
            multiset<pair<int, int>> sums;
            for (int i = 0; i < m; ++i) {
                sums.insert(pair<int, int> (0, i));
            }
            multiset<pair<int, int>>::iterator sums_it;

            vector<vector<int>> heights(m);

            map<int, int, greater<int>>::iterator it = mp.begin();
            // index of related vectors
            int mn_sum = 0, mn_idx = 0;

            for (int i = 0; i < n; ++i) {
                if (it->second == 0) {
                    ++it;
                }
                
                mn_sum = sums.begin()->first;
                mn_idx = sums.begin()->second;

                mn_sum += it->first;
                sums.erase(sums.begin());
                sums.insert(pair<int, int>(mn_sum, mn_idx));

                heights[mn_idx].push_back(it->first);
                --it->second;
            }

            mn_sum = sums.begin()->first;
            multiset<pair<int, int>>::reverse_iterator sums_rit = sums.rbegin();
            int mx_sum = sums_rit->first;
            if (mx_sum - mn_sum > x) {
                ans = false;
            }
            else {
                int original_idx;
                map<int, int>::iterator original_idx_it;
                for (int i = 0; i < m; ++i) {
                    for (auto &height: heights[i]) {
                        original_idx_it = original_indexes.find(height);
                        original_idx = original_idx_it->second;
                        output[original_idx] = i + 1;
                        original_indexes.erase(original_idx_it);
                    }
                }
            }
        }

        else {
            for (int i = 0; i < n; ++i) {
                output[i] = 1;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
        if (ans) {
            for (auto &el: output) {
                cout << el << ' ';
            } 
            cout << endl;
        }
    }

    return 0;
}
