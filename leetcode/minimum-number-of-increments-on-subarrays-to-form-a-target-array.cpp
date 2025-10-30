// 1526. Minimum Number of Increments on Subarrays to Form a Target Array
// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

#include <vector>

using std::max;
using std::vector;

// Based on Editorial's Approach: Difference Array
class Solution {
 public:
  int minNumberOperations(vector<int>& target) {
    int n = target.size();
    int ans = target[0];
    for (int i = 1; i < n; ++i) {
      ans += max(target[i] - target[i - 1], 0);
    }
    return ans;
  }
};
