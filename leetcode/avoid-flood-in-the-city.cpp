// 1488. Avoid Flood in The City
// https://leetcode.com/problems/avoid-flood-in-the-city/

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


// Wrong answer
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> lakes;
        bool flood = false;
        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            if (lake == 0) {
                if (lakes.empty()) {
                    rains[i] = 1;
                    continue;
                }
                auto [lake_to_dry, idx] = *lakes.begin();
                rains[i] = lake_to_dry;
                rains[idx] = -1;
                lakes.erase(lakes.begin());
            }
            if (lakes.count(lake)) {
                flood = true;
                break;
            }
            if (lake != 0) {
                lakes[lake] = i;
            }
        }
        if (flood) {
            return {};
        }
        for (const auto& [full_lake, idx]: lakes) {
            rains[idx] = -1;
        }
        return rains;
    }
};
