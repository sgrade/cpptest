// 2110. Number of Smooth Descent Periods of a Stock
// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/

#include <vector>

using std::vector;

class Solution {
 public:
  long long getDescentPeriods(vector<int>& prices) {
    int n = prices.size(), left = 0;
    long long ans = 1;
    for (int right = 1; right < n; ++right) {
      if (prices[right - 1] - prices[right] == 1) {
        ans += right - left + 1;
      } else {
        ans++;
        left = right;
      }
    }
    return ans;
  }
};
