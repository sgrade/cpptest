// 2300. Successful Pairs of Spells and Potions
// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::sort;


class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            long long target = ceill((double)success /spells[i]);
            vector<int>::iterator it = lower_bound(potions.begin(), potions.end(), target);
            int cur_ans = distance(it, potions.end());
            ans[i] = cur_ans;
        }
        return ans;
    }
};
