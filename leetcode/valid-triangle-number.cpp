// 611. Valid Triangle Number
// https://leetcode.com/problems/valid-triangle-number/

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;


// Based on Editorial's Approach 3: Linear Scan
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int triplets = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            int k = i + 2;
            for (int j = i + 1; j < n - 1 && nums[i] != 0; ++j) {
                while (k < n && nums[i] + nums[j] > nums[k]) {
                    ++k;
                }
                triplets += k - j - 1;
            }
        }
        return triplets;
    }
};
