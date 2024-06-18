// 826. Most Profit Assigning Work
// https://leetcode.com/problems/most-profit-assigning-work/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = difficulty.size(), m = worker.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i)
            pq.emplace(profit[i], difficulty[i]);

        sort(worker.begin(), worker.end());

        int ans = 0, workers_not_assigned = m;
        vector<int>::iterator it;
        while (!pq.empty() && m > 0) {
            auto [prof, diff] = pq.top();
            pq.pop();
            it = lower_bound(worker.begin(), worker.begin() + workers_not_assigned, diff);
            int assigned_for_current_job = distance(it, worker.begin() + workers_not_assigned);
            ans += assigned_for_current_job * prof;
            workers_not_assigned -= assigned_for_current_job;
        }

        return ans;
    }
};
