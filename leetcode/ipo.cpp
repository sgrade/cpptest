// 502. IPO
// https://leetcode.com/problems/ipo/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's A Greedy Approach
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; ++i)
            projects[i] = pair<int, int>(capital[i], profits[i]);
        sort(projects.begin(), projects.end());

        priority_queue<int> pq;
        int idx = 0;
        for (int i = 0; i < k; ++i) {
            while (idx < n && projects[idx].first <= w)
                pq.emplace(projects[idx++].second);
            if (pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
