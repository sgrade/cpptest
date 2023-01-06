// 1833. Maximum Ice Cream Bars
// https://leetcode.com/problems/maximum-ice-cream-bars/

#include <bits/stdc++.h>

using namespace std;


// SLOW
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for (const int& cost: costs) {
            coins -= cost;
            if (coins < 0) break;
            else ++ans;
        }
        return ans;
    }
};
