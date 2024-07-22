// 2093. Minimum Cost to Reach City With Discounts
// https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dijkstra's Algorithm using Priority Queue
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& highway: highways) {
            int city1 = highway[0], city2 = highway[1], toll = highway[2];
            adj[city1].emplace_back(city2, toll);
            adj[city2].emplace_back(city1, toll);
        }
        // <toll, city, discounts_used>
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        
        // Total cost to reach a city using number of discounts 
        vector<vector<int>> costs (n, vector<int>(discounts + 1, numeric_limits<int>::max()));
        costs[0][0] = 0;
        vector<vector<bool>> visited(n, vector<bool>(discounts + 1));
        while (!pq.empty()) {
            int current_cost, city, discounts_used;
            tie(current_cost, city, discounts_used) = pq.top();
            pq.pop();
            if (visited[city][discounts_used])
                continue;
            visited[city][discounts_used] = true;
            for (const auto& [neighbor, toll]: adj[city]) {
                // Don't use a discount
                if (current_cost + toll < costs[neighbor][discounts_used]) {
                    costs[neighbor][discounts_used] = current_cost + toll;
                    pq.emplace(costs[neighbor][discounts_used], neighbor, discounts_used);
                }
                // Use a discount
                if (discounts_used < discounts) {
                    int cost_with_discount = current_cost + toll / 2;
                    if (cost_with_discount < costs[neighbor][discounts_used + 1]) {
                        costs[neighbor][discounts_used + 1] = cost_with_discount;
                        pq.emplace(cost_with_discount, neighbor, discounts_used + 1);
                    }
                }
            }
        }

        int ans = *min_element(costs[n - 1].begin(), costs[n - 1].end());
        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};
