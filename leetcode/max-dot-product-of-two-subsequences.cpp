// 1458. Max Dot Product of Two Subsequences
// https://leetcode.com/problems/max-dot-product-of-two-subsequences/

#include <algorithm>
#include <vector>

using namespace std;

// Based on Editorial's Approach 1: Top-Down Dynamic Programming
// Time Limit Exceeded: 67 / 69 testcases passed
class Solution {
 public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    const auto [min1, max1] = minmax_element(nums1.begin(), nums1.end());
    const auto [min2, max2] = minmax_element(nums2.begin(), nums2.end());
    if (*max1 < 0 && *min2 > 0) {
      return *max1 * *min2;
    }
    if (*max2 < 0 && *min1 > 0) {
      return *max2 * *min1;
    }

    vector<vector<int>> memo(nums1.size(), vector<int>(nums2.size()));
    return GetDotProduct(0, 0, nums1, nums2, memo);
  }

 private:
  int GetDotProduct(size_t idx1, size_t idx2, vector<int>& nums1,
                    vector<int>& nums2, vector<vector<int>>& memo) {
    if (idx1 == nums1.size() || idx2 == nums2.size()) {
      return 0;
    }

    if (memo[idx1][idx2] != 0) {
      return memo[idx1][idx2];
    }

    int move_both = nums1[idx1] * nums2[idx2] +
                    GetDotProduct(idx1 + 1, idx2 + 1, nums1, nums2, memo);
    int move_idx1 = GetDotProduct(idx1 + 1, idx2, nums1, nums2, memo);
    int move_idx2 = GetDotProduct(idx1, idx2 + 1, nums1, nums2, memo);
    memo[idx1][idx2] = max({move_both, move_idx1, move_idx2});
    return memo[idx1][idx2];
  }
};
