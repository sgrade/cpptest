// 3573. Best Time to Buy and Sell Stock V
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/

#include <vector>

using std::max;
using std::vector;

// States: IDLE (no position), LONG (bought, will sell), SHORT (sold, will buy
// back)
constexpr int IDLE = 0, LONG = 1, SHORT = 2;

class Solution {
 public:
  long long maximumProfit(vector<int>& prices, int k) {
    int n = prices.size();

    // dp[transactions][state] = max profit using 'transactions' transactions in
    // 'state'
    vector<vector<long long>> dp(k + 1, vector<long long>(3));

    // Initialize: on day 0, can enter LONG (buy) or SHORT (sell) position
    for (int transactions = 1; transactions <= k; ++transactions) {
      dp[transactions][LONG] = -prices[0];  // Bought at prices[0]
      dp[transactions][SHORT] = prices[0];  // Sold short at prices[0]
    }

    for (int day = 1; day < n; day++) {
      int price = prices[day];
      // Process transactions in reverse to avoid using updated values
      for (int transactions = k; transactions > 0; transactions--) {
        // IDLE: stay idle, or close LONG (sell), or close SHORT (buy back)
        dp[transactions][IDLE] =
            max(dp[transactions][IDLE], max(dp[transactions][LONG] + price,
                                            dp[transactions][SHORT] - price));
        // LONG: hold position, or enter from previous transactions's IDLE (buy)
        dp[transactions][LONG] =
            max(dp[transactions][LONG], dp[transactions - 1][IDLE] - price);
        // SHORT: hold position, or enter from previous transactions's IDLE
        // (sell short)
        dp[transactions][SHORT] =
            max(dp[transactions][SHORT], dp[transactions - 1][IDLE] + price);
      }
    }

    return dp[k][IDLE];
  }
};
