// 163. Missing Ranges
// https://leetcode.com/problems/missing-ranges/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> findMissingRanges(vector<int>& nums, int lower,
                                        int upper) {
    int n = nums.size();
    if (n == 0) {
      return {{lower, upper}};
    }
    vector<vector<int>> ans;
    if (lower < nums[0]) {
      ans.emplace_back(vector<int>{lower, nums[0] - 1});
    }
    for (int i = 1; i < n; ++i) {
      if (nums[i] - nums[i - 1] == 1) {
        continue;
      }
      ans.emplace_back(vector<int>{nums[i - 1] + 1, nums[i] - 1});
    }
    if (nums[n - 1] < upper) {
      ans.emplace_back(vector<int>{nums[n - 1] + 1, upper});
    }
    return ans;
  }
};
