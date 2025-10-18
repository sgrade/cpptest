// 3397. Maximum Number of Distinct Elements After Operations
// https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/

#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
using std::sort;
using std::max;
using std::min;


// Based on Editorial's Approach: Greedy
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mn = INT_MIN, distinct = 0;
        for (const int num: nums) {
            int cur_mn = max(num - k, mn + 1);
            int cur = min(cur_mn, num + k);
            if (cur > mn) {
                ++distinct;
                mn = cur;
            }
        }
        return distinct;
    }
};
