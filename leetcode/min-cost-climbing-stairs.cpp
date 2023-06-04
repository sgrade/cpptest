// 746. Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.emplace_back(0);
        for (int i = 2; i < cost.size(); ++i) {
            cost[i] += min(cost[i - 2], cost[i - 1]);
        }
        return cost.back();
    }
};
