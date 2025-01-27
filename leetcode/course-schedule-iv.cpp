// 1462. Course Schedule IV
// https://leetcode.com/problems/course-schedule-iv/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Tree Traversal - Preprocessed
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = numCourses;
        for (const vector<int>& p: prerequisites)
            adj[p[0]].emplace_back(p[1]);
        is_prerequisite.resize(n, vector<bool>(n));
        getPrerequisites(prerequisites);
        vector<bool> ans;
        for (const vector<int>& q: queries)
            ans.emplace_back(is_prerequisite[q[0]][q[1]]);
        return ans;
    }

private:
    int n;
    unordered_map<int, vector<int>> adj;
    vector<vector<bool>> is_prerequisite;
    void getPrerequisites(vector<vector<int>>& prerequisites) {
        for (int i = 0; i < n; ++i) {
            queue<int> q;
            q.emplace(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (const int& neighbor: adj[node]) {
                    if (!is_prerequisite[i][neighbor]) {
                        is_prerequisite[i][neighbor] = true;
                        q.emplace(neighbor);
                    }
                }
            }
        }
    }
};
