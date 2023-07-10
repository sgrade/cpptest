// 983. Minimum Cost For Tickets
// https://leetcode.com/problems/minimum-cost-for-tickets/

#include <bits/stdc++.h>

using namespace std;


// Wrong Answer
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        return traverse(0, 0, 0, days, costs);
    }

private:
    int n;
    vector<int> x = {1, 7, 30};
    int traverse (int i, int valid_until, int total_cost, vector<int>& days, vector<int>& costs) {
        if (i >= n - 1) return total_cost;
        int current_cost = numeric_limits<int>::max();
        for (int j = 0; j < 3; ++j) {
            current_cost = min(
                current_cost, 
                traverse(i + 1, days[i] + x[j], total_cost + costs[j], days, costs)
            );
        }
        if (days[i] < valid_until) {
            current_cost = min (
                current_cost,
                traverse(i + 1, valid_until, total_cost, days, costs)
            );
        }
        return current_cost;
    }
};
