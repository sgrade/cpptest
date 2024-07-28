// 2045. Second Minimum Time to Reach Destination
// https://leetcode.com/problems/second-minimum-time-to-reach-destination/

#include <bits/stdc++.h>

using namespace std;


// Fixed wrong answer with some ideas from Editorial's Approach 2: Breadth First Search
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

        int ans = -1;
        int current_time = 0;
        queue<int> q;
        vector<pair<int, int>> distance (n + 1, {-1, -1});
        q.emplace(1);
        while (!q.empty()) {
            bool green = (current_time / change) % 2 == 0;
            if (green)
                current_time += time;
            else
                current_time = change * (current_time / change + 1) + time;
            int nodes = q.size();
            for (int i = 0; i < nodes; ++i) {
                int node = q.front();
                q.pop();
                for (const int& neighbor: adj[node]) {
                    if (distance[neighbor].first == -1) {
                        distance[neighbor].first = current_time;
                        q.emplace(neighbor);
                    }
                    else if (distance[neighbor].second == -1 && distance[neighbor].first != current_time) {
                        if (neighbor == n)
                            return current_time;
                        distance[neighbor].second = current_time;
                        q.emplace(neighbor);
                    }
                }
            }
        }
        return -1;
    }
};
