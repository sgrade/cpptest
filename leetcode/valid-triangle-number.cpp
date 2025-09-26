// 611. Valid Triangle Number
// https://leetcode.com/problems/valid-triangle-number/

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;


// Optimized two-pointer approach (O(n^2) time, O(1) extra space)
// Use a fixed largest side and two pointers to count valid pairs efficiently.
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int triplets = 0;
        // If the smallest value is 0 then any triangle including it can't be valid
        // when that 0 is one of the two smaller sides. We still need to check
        // combinations where all sides > 0, so we don't early return here unless
        // all numbers are zero.
        int right = n - 1;
        for (; right >= 2; --right) {
            if (nums[right] == 0) {
                break; // all remaining are zero
            }
            int left = 0, mid = right - 1;
            while (left < mid) {
                // nums[left] + nums[mid] > nums[right] => all between l..mid-1 paired with mid are valid
                if (nums[left] + nums[mid] > nums[right]) {
                    triplets += (mid - left);
                    --mid;
                } else {
                    ++left;
                }
            }
        }
        return triplets;
    }
};
