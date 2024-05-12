// 743. Network Delay Time
// https://leetcode.com/problems/network-delay-time/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Breadth-First Search (BFS)
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

        vector<int> signal_received_at(n + 1, INT_MAX);
        Bfs(signal_received_at, k);

        int ans = INT_MIN;
        for (int node = 1; node <= n; ++node)
            ans = max(ans, signal_received_at[node]);

        return ans == INT_MAX ? -1 : ans;
    }
private:
    vector<vector<pair<int, int>>> adj;
    void Bfs(vector<int>& signal_received_at, const int& k) {
        queue<int> q;
        q.emplace(k);
        signal_received_at[k] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (const auto& [time, neighbor]: adj[node]) {
                int arrival_time = signal_received_at[node] + time;
                if (signal_received_at[neighbor] > arrival_time) {
                    signal_received_at[neighbor] = arrival_time;
                    q.emplace(neighbor);
                }
            }
        }
    }
};
