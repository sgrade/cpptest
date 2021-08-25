// C. Deep Down Below

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
        int power_increase_after_cave;

        for (int i = 0; i < n; ++i) {
            min_power_to_enter = 0;
            for (int j = 0; j < v[i].size(); ++j) {
                min_power_to_enter = max(min_power_to_enter, v[i][j] + 1 - j);
            }
            power_increase_after_cave = v[i].size();
            mst.insert(pair<int, int>(min_power_to_enter, power_increase_after_cave));
        }
        
        auto it = begin(mst);
        pair<int, int> prev = *it;
        ans = prev.first;
        power_increase_after_cave = prev.second;
        ++it;

        while (it != end(mst)) {
            min_power_to_enter = it->first;
            if (ans + power_increase_after_cave < min_power_to_enter) {
                ans += max(0, min_power_to_enter - (ans + power_increase_after_cave));
            }
            power_increase_after_cave += it->second;
            ++it;
        }

        cout << ans << endl;

    }

    return 0;
}
