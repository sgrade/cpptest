// 1235. Maximum Profit in Job Scheduling
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Top-Down Dynamic Programming + Binary Search
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memo.resize(50001, -1);
        for (int i = 0; i < n; ++i)
            jobs.emplace_back(vector<int>{startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        for (int i = 0; i < n; ++i)
            startTime[i] = jobs[i][0];
        return findMaxProfit(startTime, 0);
    }
private:
    int n;
    vector<int> memo;
    vector<vector<int>> jobs;
    int findMaxProfit(vector<int>& startTime, int idx) {
        if (idx == n)
            return 0;
        if (memo[idx] != -1)
            return memo[idx];
        int nextIdx = lower_bound(startTime.begin(), startTime.end(), jobs[idx][1]) - startTime.begin();
        int max_profit = max(findMaxProfit(startTime, idx + 1), jobs[idx][2] + findMaxProfit(startTime, nextIdx));
        return memo[idx] = max_profit;
    }
};
