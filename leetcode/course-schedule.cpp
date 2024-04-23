// 207. Course Schedule
// https://leetcode.com/problems/course-schedule/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Topological Sort Using Kahn's Algorithm
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (const vector<int>& p: prerequisites) {
            adj[p[1]].emplace_back(p[0]);
            ++indegree[p[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.emplace(i);
        }

        int nodes_visited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ++nodes_visited;
            for (const int& neighbor: adj[node]) {
                --indegree[neighbor];
                if (indegree[neighbor] == 0)
                    q.emplace(neighbor);
            }
        }

        return nodes_visited == numCourses;
    }
};
