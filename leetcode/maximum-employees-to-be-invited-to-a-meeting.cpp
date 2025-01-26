// 2127. Maximum Employees to Be Invited to a Meeting
// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Topological Sort to Reduce Non-Cyclic Nodes
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = favorite.size();
        vector<int> indegree(n);
        for (const int& f: favorite)
            ++indegree[f];
        queue<int> q;
        for (int person = 0; person < n; ++person) {
            if (indegree[person] == 0)
                q.emplace(person);
        }

        vector<int> depths(n, 1);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            int next = favorite[current];
            depths[next] = max(depths[next], depths[current] + 1);
            if (--indegree[next] == 0)
                q.emplace(next);
        }

        int longest_cycle = 0, mutuals = 0;
        for (int person = 0; person < n; ++person) {
            // Already processed
            if (indegree[person] == 0)
                continue;
            int cycle_len = 0, current = person;
            while (indegree[current] != 0) {
                indegree[current] = 0;  // Mark visited
                ++cycle_len;
                current = favorite[current];
            }
            if (cycle_len == 2)
                mutuals += depths[person] + depths[favorite[person]];
            else
                longest_cycle = max(longest_cycle, cycle_len);
        }
        return max(longest_cycle, mutuals);
    }
};
