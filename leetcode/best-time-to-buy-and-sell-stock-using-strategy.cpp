// 3652. Best Time to Buy and Sell Stock using Strategy
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/

#include <vector>

using namespace std;

// Based on Editorial's Approach: Prefix Sum
class Solution {
 public:
  long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
    int n = prices.size();
    vector<long long> profit_sum(n + 1), price_sum(n + 1);
    for (int i = 0; i < n; ++i) {
      profit_sum[i + 1] = profit_sum[i] + prices[i] * strategy[i];
      price_sum[i + 1] = price_sum[i] + prices[i];
    }

    long long ans = profit_sum[n];
    for (int i = k - 1; i < n; ++i) {
      long long left = profit_sum[i - k + 1];
      long long right = profit_sum[n] - profit_sum[i + 1];
      long long change = price_sum[i + 1] - price_sum[i - k / 2 + 1];
      ans = max(ans, left + change + right);
    }
    return ans;
  }
};
