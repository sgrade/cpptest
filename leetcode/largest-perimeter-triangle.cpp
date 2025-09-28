// 976. Largest Perimeter Triangle
// https://leetcode.com/problems/largest-perimeter-triangle/

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 3; i >= 0; --i) {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};
