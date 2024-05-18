// 787. Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <bits/stdc++.h>

using namespace std;


// Time Limit Exceeded
// 28 / 54 testcases passed
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& f: flights) {
            int from_city = f[0], to_city = f[1], price = f[2];
            adj[from_city].emplace_back(to_city, price);
        }

        // <price, {stops_left, total_price, to_city}>
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
            > pq;

        int ans = numeric_limits<int>::max();
        for (const auto& [to_city, price]: adj[src])
            pq.emplace(price, vector<int>{k, 0, to_city});

        while (!pq.empty()) {
            const auto [price, v] = pq.top();
            int stops_left = v[0], total_price = v[1], current_city = v[2];
            pq.pop();
            total_price += price;
            if (current_city == dst)
                ans = min(ans, total_price);
            if (stops_left > 0) {
                for (const auto& [to_city, price]: adj[current_city])
                    pq.emplace(price, vector<int>{stops_left - 1, total_price, to_city});
            }
        }

        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};
