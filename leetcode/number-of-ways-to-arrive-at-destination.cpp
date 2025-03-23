// 1976. Number of Ways to Arrive at Destination
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dijkstra's Algorithm
class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            adj.resize(n);
            for (const vector<int>& r: roads) {
                int start = r[0], end = r[1], time = r[2];
                adj[start].emplace_back(end, time);
                adj[end].emplace_back(start, time);
            }

            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            vector<long long> shortest_time(n, numeric_limits<long long>::max());
            vector<int> paths(n);
            shortest_time[0] = 0;
            paths[0] = 1;
            pq.emplace(0, 0);

            while (!pq.empty()) {
                auto [cur_time, node] = pq.top();
                pq.pop();
                if (cur_time > shortest_time[node])
                    continue;
                for (const auto& [neighbor, road_time] : adj[node]) {
                    long long total_time = cur_time + road_time;
                    if (total_time < shortest_time[neighbor]) {
                        shortest_time[neighbor] = cur_time + road_time;
                        paths[neighbor] = paths[node];
                        pq.emplace(shortest_time[neighbor], neighbor);
                    }
                    else if (total_time == shortest_time[neighbor]) {
                        paths[neighbor] = (paths[neighbor] + paths[node]) % MOD;
                    }
                }
            }

            return paths[n - 1];
        }

    private:
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj;
    };
