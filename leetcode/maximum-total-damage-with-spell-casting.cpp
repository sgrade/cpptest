// 3186. Maximum Total Damage With Spell Casting
// https://leetcode.com/problems/maximum-total-damage-with-spell-casting/

#include <vector>
#include <map>

using std::vector;
using std::map;
using std::pair;
using std::max;


// Based on Editorial's Approach: Dynamic Programming
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> counter;
        for (const int spell: power) {
            ++counter[spell];
        }

        vector<pair<int, int>> spells;
        spells.emplace_back(-1e9, 0);
        for (const auto& p: counter) {
            spells.emplace_back(p);
        }

        int n = spells.size();
        long long mx = 0;
        vector<long long> cur_ans(n);
        for (int i = 1, j = 1; i < n; ++i) {
            while (j < i && spells[j].first < spells[i].first - 2) {
                mx = max(mx, cur_ans[j]);
                ++j;
            }
            cur_ans[i] = mx + 1LL * spells[i].first * spells[i].second;
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, cur_ans[i]);
        }
        return ans;
    }
};
