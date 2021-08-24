// C. Deep Down Below
// Wrong answer on test 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<vector<int>> v;

        for (int i = 0; i < n; ++i) {

            int k;
            cin >> k;

            vector<int> a(k);

            for (auto &el: a) {
                cin >> el;

            }

            v.push_back(a);

        }

        int ans = 0;

        multiset<pair<int, int>> mst;
        int min_power_to_enter;
        int power_increse_after_cave;

        for (int i = 0; i < n; ++i) {
            auto mx_it = max_element(begin(v[i]), end(v[i]));
            int mx = *mx_it;
            int mx_idx = distance(begin(v[i]), mx_it);
            min_power_to_enter = mx + 1 - mx_idx;
            power_increse_after_cave = v[i].size();
            mst.insert(pair<int, int>(min_power_to_enter, power_increse_after_cave));
        }
        
        auto it = begin(mst);
        pair<int, int> prev = *it;
        ans = prev.first;
        power_increse_after_cave = prev.second;
        ++it;

        while (it != end(mst)) {
            min_power_to_enter = it->first;
            if (ans + power_increse_after_cave < min_power_to_enter) {
                ans += min_power_to_enter - (ans + power_increse_after_cave);
            }
            power_increse_after_cave = it->second;
            ++it;
        }

        cout << ans << endl;

    }

    return 0;
}
