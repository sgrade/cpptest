// 2110. Number of Smooth Descent Periods of a Stock
// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/

#include <vector>

using std::vector;

class Solution {
 public:
  long long getDescentPeriods(vector<int>& prices) {
    int len = 1;
    long long ans = 1;
    for (size_t right = 1; right < prices.size(); ++right) {
      if (prices[right - 1] - prices[right] == 1) {
        len++;
      } else {
        len = 1;
      }
      ans += len;
    }
    return ans;
  }
};
