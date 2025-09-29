// 1121. Divide Array Into Increasing Sequences
// https://leetcode.com/problems/divide-array-into-increasing-sequences/

#include <vector>

using std::vector;


// Based on Editorial's Approach: Maximum Value
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        int cur = nums[0], cnt = 0;
        for (const int num: nums) {
            if (num == cur) {
                ++cnt;
            } else {
                cur = num;
                cnt = 1;
            }
            if (cnt * k > nums.size()) {
                return false;
            }
        }
        return true;
    }
};
