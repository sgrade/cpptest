// 2045. Second Minimum Time to Reach Destination
// https://leetcode.com/problems/second-minimum-time-to-reach-destination/

#include <bits/stdc++.h>

using namespace std;


// Wrong Answer
// 69 / 76 testcases passed
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<vector<int>> adj (n + 1);
        for (const vector<int>& edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        int ans = 0;
        int current_time = 0;
        queue<int> q;
        vector<int> visited (n + 1);
        q.emplace(1);
        visited[1] = 1;
        while (!q.empty()) {
            bool green = (current_time / change) % 2 == 0;
            if (green)
                current_time += time;
            else {
                int rem = current_time % change;
                current_time += (change - rem) + time;
            }
            int nodes = q.size();
            for (int i = 0; i < nodes; ++i) {
                int node = q.front();
                q.pop();
                for (const int& neighbor: adj[node]) {
                    if (neighbor == n) {
                        if (ans == 0 || current_time != ans)
                            ans = current_time;
                        else
                            return current_time;
                    }
                    if (visited[neighbor] == 2)
                        continue;
                    q.emplace(neighbor);
                    ++visited[neighbor];
                }
            }
        }
        return ans;
    }
};
