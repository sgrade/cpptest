// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = 0, mn = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            ans = max(ans, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};
