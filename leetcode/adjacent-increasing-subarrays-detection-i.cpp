// 3349. Adjacent Increasing Subarrays Detection I
// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/

#include <vector>

using std::vector;


class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int i = 0, n = nums.size();
        while (i < n - k) {
            bool down = false;
            int j = i + 1;
            while (j < n && nums[j - 1] < nums[j]) {
                ++j;
            }
            if (j - i >= 2 * k) {
                return true;
            }
            if (j - i < k) {
                i = j;
                continue;
            }
            
            int x = j + 1;
            while (x < n && nums[x - 1] < nums[x]) {
                ++x;
            }
            if (x - j >= 2 * k)  {
                return true;
            }
            if (x - j >= k) {
                return true;
            }
            i = x;
        }
        return false;
    }
};
