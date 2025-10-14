// 3349. Adjacent Increasing Subarrays Detection I
// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/

#include <vector>

using std::vector;


class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), prev = 0, cur = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] < nums[i]) {
                ++cur;
                if (cur >= 2 * k) {
                    return true;
                }
            }
            else {
                prev = cur;
                cur = 1;
            }
            if (prev >= k && cur >= k) {
                return true;
            }
        }
        return false;
    }
};
