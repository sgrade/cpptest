// 743. Network Delay Time
// https://leetcode.com/problems/network-delay-time/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Depth-First Search (DFS)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        adj.resize (101);
        for (const vector<int>& time: times) {
            int source = time[0], dest = time[1], travel_time = time[2];
            adj[source].emplace_back(travel_time, dest);
        }
        for (vector<pair<int, int>>& v: adj)
            sort(v.begin(), v.end());

        vector<int> signal_received_at(n + 1, INT_MAX);
        dfs(signal_received_at, k, 0);

        int ans = INT_MIN;
        for (int node = 1; node <= n; ++node)
            ans = max(ans, signal_received_at[node]);

        return ans == INT_MAX ? -1 : ans;
    }
private:
    vector<vector<pair<int, int>>> adj;
    void dfs(vector<int>& signal_received_at, int current_node, int current_time) {
        if (current_time >= signal_received_at[current_node])
            return;
        signal_received_at[current_node] = current_time;
        for (auto& [travel_time, neighbor_node]: adj[current_node])
            dfs(signal_received_at, neighbor_node, current_time + travel_time);
    }
};
