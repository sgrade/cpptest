// 1672. Richest Customer Wealth
// https://leetcode.com/problems/richest-customer-wealth/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (int i = 0; i < accounts.size(); ++i) {
            int money = 0;
            for (int j = 0; j < accounts[0].size(); ++j) {
                money += accounts[i][j];
            }
            ans = max(ans, money);
        }
        return ans;
    }
};
