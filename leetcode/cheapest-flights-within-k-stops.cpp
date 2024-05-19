// 787. Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <bits/stdc++.h>

using namespace std;


// BFS
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& f: flights) {
            int from_city = f[0], to_city = f[1], flight_price = f[2];
            adj[from_city].emplace_back(to_city, flight_price);
        }

        // {total_price, to_city}
        queue<pair<int, int>> q;
        q.emplace(0, src);
        vector<int> visited(n, numeric_limits<int>::max());
        int stops = 0;
        while (stops <= k && !q.empty()) {
            int sz = q.size();
            while (sz--) {
                const auto [total_price, from_city] = q.front();
                q.pop();
                for (const auto& [to_city, flight_price]: adj[from_city]) {
                    int current_price = total_price + flight_price;
                    if (current_price >= visited[to_city])
                        continue;
                    visited[to_city] = current_price;
                    q.emplace(current_price, to_city);
                }
            }
            ++stops;
        }

        return visited[dst] == numeric_limits<int>::max() ? -1 : visited [dst];
    }
};
