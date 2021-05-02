// C. Phoenix and Towers
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>

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
            original_indexes.insert(tmp, i);
        }

        bool ans = true;
        vector<int> output(n);

        if (m > 1) {
            // index of related vectors
            int mn_sum = 0, next_mn_sum = 1, mn_idx, next_mn_idx = 1;

            // [0] = sum, v[1...] = heights>
            vector<int> sums;
            vector<vector<int>> heights(m);
            map<int, int>::iterator it = mp.begin();
            for (int i = 0; i < n; ++i) {
                if (it->second == 0) {
                    ++it;
                }

                sums[mn_idx] += it->first;
                heights[mn_idx].push_back(it->first);
                --it->second;

                tmp = mn_sum + it->second;
                if (tmp > next_mn_sum) {
                    mn_sum = next_mn_sum;
                    mn_idx = next_mn_idx;
                    auto mn_it = min_element(sums.begin(), sums.end());
                    mn_sum = *mn_it;
                    mn_idx = distance(sums.begin(), mn_it);
                }
            }

            auto min_max = minmax_element(sums.begin(), sums.end());
            if (min_max.second - min_max.first > x) {
                ans = false;
            }
            else {
                int original_idx;
                map<int, int>::iterator original_idx_it;
                for (int i = 0; i < m; ++i) {
                    for (auto &height: heights[i]) {
                        original_idx_it = find(original_indexes.begin(), original_indexes.end(), height);
                        
                    }
                }
            }
        }

        else {
            for (auto &el: h) {
                output[el.second] = el.first;
            }
        } 
    }

    return 0;
}
