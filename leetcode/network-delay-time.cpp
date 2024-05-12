// 743. Network Delay Time
// https://leetcode.com/problems/network-delay-time/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Dijkstra's Algorithm
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
        Dijkstra(signal_received_at, k, n);

        int ans = INT_MIN;
        for (int node = 1; node <= n; ++node)
            ans = max(ans, signal_received_at[node]);

        return ans == INT_MAX ? -1 : ans;
    }
private:
    vector<vector<pair<int, int>>> adj;
    void Dijkstra(vector<int>& signal_received_at, const int& k, const int& n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, k);
        signal_received_at[k] = 0;
        while (!pq.empty()) {
            const auto [current_time, node] = pq.top();
            pq.pop();
            if (current_time > signal_received_at[node])
                continue;
            for (const auto& [time, neighbor]: adj[node]) {
                int time_through_current_node = current_time + time;
                if (signal_received_at[neighbor] > time_through_current_node) {
                    signal_received_at[neighbor] = time_through_current_node;
                    pq.emplace(time_through_current_node, neighbor);
                }
            }
        }
    }
};
