// 983. Minimum Cost For Tickets
// https://leetcode.com/problems/minimum-cost-for-tickets/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Bottom-up Dynamic Programming
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int last_day = days[n - 1];
        vector<int> dp(last_day + 1);
        
        int i = 0;
        for (int day = 1; day <= last_day; ++day) {
            if (day < days[i]) {
                dp[day] = dp[day - 1];
            }
            else {
                ++i;
                dp[day] = min({
                    dp[day - 1] + costs[0],
                    dp[max(0, day - 7)] + costs[1],
                    dp[max(0, day - 30)] + costs[2]
                });
            }
        }

        return dp[last_day];
    }
};
