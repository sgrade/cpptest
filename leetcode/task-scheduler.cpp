// 621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/

#include <bits/stdc++.h>

using namespace std;


// Optimized with ideas from Editorial's Approach 1: Using Priority Queue / Max Heap
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> counter(26);
        for (const char& task: tasks)
            ++counter[task - 'A'];
        priority_queue<int> pq;
        for (const int& cnt: counter)
            if (cnt > 0)
                pq.emplace(cnt);
        int ans = 0;
        while (!pq.empty()) {
            int nn = n + 1, cur, tasks = 0;
            queue<int> q;
            while (!pq.empty() && nn--) {
                cur = pq.top();
                pq.pop();
                if (--cur > 0)
                    q.emplace(cur);
                ++tasks;
            }
            while (!q.empty()) {
                pq.emplace(q.front());
                q.pop();
            }
            ans += pq.empty() ? tasks : n + 1;
        }
        return ans;
    }
};
