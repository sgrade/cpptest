// 2221. Find Triangular Sum of an Array
// https://leetcode.com/problems/find-triangular-sum-of-an-array/

#include <vector>

using std::vector;


class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while (--n) {
            for (int i = 1; i < nums.size(); ++i) {
                nums[i - 1] = (nums[i - 1] + nums[i]) % 10;
            }
        }
        return nums[0];
    }
};
