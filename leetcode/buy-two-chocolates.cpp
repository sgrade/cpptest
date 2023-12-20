// 2706. Buy Two Chocolates
// https://leetcode.com/problems/buy-two-chocolates/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int ans = money - prices[0] - prices[1];
        if (ans < 0)
            return money;
        return ans;
    }
};
