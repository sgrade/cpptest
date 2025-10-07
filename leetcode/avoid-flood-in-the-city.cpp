// 1488. Avoid Flood in The City
// https://leetcode.com/problems/avoid-flood-in-the-city/

#include <vector>
#include <unordered_map>
#include <set>

using std::vector;
using std::unordered_map;
using std::set;


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        set<int> dry_days;
        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dry_days.emplace(i);
            }
        }

        vector<int> ans(n, 1);
        unordered_map<int, int> full_lakes;
        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            
            if (lake == 0) {
                continue;
            }

            // lake != 0
            if (full_lakes.find(lake) == full_lakes.end()) {
                full_lakes[lake] = i;
                ans[i] = -1;
                continue;
            } 
            
            // else - need to dry the lake
            if (dry_days.empty()) {
                return {};
            }
            int day_when_lake_filled = full_lakes[lake];
            auto dry_day_it = dry_days.lower_bound(day_when_lake_filled);
            if (dry_day_it == dry_days.end()) {
                return {};
            }
            int dry_day = *dry_day_it;
            if (dry_day > i) {
                return {};
            }
            ans[dry_day] = lake;
            full_lakes[lake] = i;
            ans[i] = -1;
            dry_days.erase(dry_day_it);
            ans[i] = -1;
        }

        return ans;
    }
};
