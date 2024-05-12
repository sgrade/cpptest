// 2473. Minimum Cost to Buy Apples
// https://leetcode.com/problems/minimum-cost-to-buy-apples/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 1: Shortest Path
class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        adj.resize(n, vector<pair<int, int>>());
        for (const auto& road: roads) {
            int city_a = road[0] - 1, city_b = road[1] - 1, cost = road[2];
            adj[city_a].emplace_back(city_b, cost);
            adj[city_b].emplace_back(city_a, cost);
        }
        vector<long long> ans(n);
        for (int start_city = 0; start_city < n; ++start_city)
            ans[start_city] = ShortestPath(start_city, appleCost, k, n);
        return ans;
    }
private:
    // <edge, weight>
    vector<vector<pair<int, int>>> adj;
    long long ShortestPath(const int& start_city, const vector<int>& appleCost, const int& k, int n) {
        vector<int> travel_costs(n, INT_MAX);
        travel_costs[start_city] = 0;
        // <cost, city>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, start_city);
        long long min_cost = INT_MAX;
        while (!pq.empty()) {
            const auto [travel_cost, current_city] = pq.top();
            pq.pop();
            long long current_cost = 1LL * appleCost[current_city] + (k + 1) * travel_cost;
            min_cost = min(min_cost, current_cost);
            for (const auto& [neighbor, cost_to_neighbor]: adj[current_city]) {
                int next_cost = travel_cost + cost_to_neighbor;
                if (next_cost < travel_costs[neighbor]) {
                    travel_costs[neighbor] = next_cost;
                    pq.emplace(next_cost, neighbor);
                }
            }
        }
        return min_cost;
    }
};
