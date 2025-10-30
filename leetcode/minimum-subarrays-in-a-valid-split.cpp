// 2464. Minimum Subarrays in a Valid Split
// https://leetcode.com/problems/minimum-subarrays-in-a-valid-split/

#include <numeric>
#include <vector>

using std::gcd;
using std::min;
using std::vector;

// Based on Editorial's Approach: Dynamic Programming
class Solution {
 public:
  int validSubarraySplit(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1, 1e5);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        if (gcd(nums[i - 1], nums[j - 1]) != 1) {
          dp[i] = min(dp[i], dp[j - 1] + 1);
        }
      }
    }
    return dp[n] == 1e5 ? -1 : dp[n];
  }
};
