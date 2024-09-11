// 210. Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Using Node Indegree
// Topological sort
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        indegree.resize(numCourses);
        vector<int> topological_order;

        for (int i = 0; i < prerequisites.size(); ++i) {
            int dest = prerequisites[i][0], src = prerequisites[i][1];
            adj[src].emplace_back(dest);
            ++indegree[dest];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.emplace(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topological_order.emplace_back(node);
            for (const int& neighbor: adj[node]) {
                --indegree[neighbor];
                if (indegree[neighbor] == 0)
                    q.emplace(neighbor);
            }
        }

        if (topological_order.size() == numCourses)
            return topological_order;
        return {};
    }

private:
    int n;
    bool ans = true;
    vector<int> output;
    map<int, list<int>> adj;
    vector<int> indegree;
};
