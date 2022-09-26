// 210. Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool ans = true;
    vector<int> output;
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {       
        vector<vector<int>> adj(numCourses);
        // 0 - not visited, 1 - checking prerequisites, 2 - all prerequisites are met
        vector<int> visited(numCourses);
        
        for (const vector<int>& v: prerequisites) {
            adj[v[1]].emplace_back(v[0]);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (!ans) {
                break;
            }
            if (visited[i] == 0) {
                dfs(i, adj, visited);
            }
        }
        
        if (!ans) {
            output.clear();
        }
        else {
            for (int i = 0; i < numCourses; ++i) {
                if (visited[i] == 0) {
                    output.emplace_back(i);
                }
            }
            reverse(output.begin(), output.end());
        }
        
        return output;
    }
    
    void dfs(int i, const vector<vector<int>> &adj, vector<int> &visited) {
        if (!ans) {
            return;
        }
        visited[i] = 1;
        int prereq;
        for (int j = 0; j < adj[i].size(); ++j) {
            prereq = adj[i][j];
            if (visited[prereq] == 1) {
                ans = false;
                return;
            }
            else if (visited[prereq] == 0) {
                dfs(prereq, adj, visited);
            }
        }
        
        visited[i] = 2;
        output.emplace_back(i);
    }
};
