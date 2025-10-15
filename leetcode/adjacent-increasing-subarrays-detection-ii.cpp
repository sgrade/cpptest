// 3350. Adjacent Increasing Subarrays Detection II
// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/

#include <vector>

using std::vector;
using std::max;
using std::min;


class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size(), prev = 0, cur = 1;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] < nums[i]) {
                ++cur;
            }
            else {
                prev = cur;
                cur = 1;
            }
            ans = max(ans, min(prev, cur));
            ans = max(ans, cur / 2);
        }
        return ans;
    }
};
