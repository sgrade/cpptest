// 1833. Maximum Ice Cream Bars
// https://leetcode.com/problems/maximum-ice-cream-bars/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 2: Counting Sort (Greedy)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int m = *max_element(costs.begin(), costs.end());
        vector<int> counter (m + 1);
        for (const int& cost: costs) {
            ++counter[cost];
        }

        int ans = 0, bars;
        for (int cost = 1; cost < m + 1 && coins >= cost; ++cost) {
            if (counter[cost] == 0) continue;
            bars = min(counter[cost], coins / cost);
            ans += bars;
            coins -= cost * bars;
        }
        return ans;
    }
};
