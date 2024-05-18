// 787. Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& f: flights) {
            int from_city = f[0], to_city = f[1], price = f[2];
            adj[from_city].emplace_back(to_city, price);
        }

        // {total_price, stops, to_city}
        priority_queue<
            vector<int>, vector<vector<int>>, greater<vector<int>>
            > pq;
        pq.emplace(vector<int>{0, 0, src});

        // Visited with steps - the idea is from Editorial's Approach 3: Dijkstra
        vector<int> visited(n, numeric_limits<int>::max());

        while (!pq.empty()) {
            const vector<int>& v = pq.top();
            int total_price = v[0], stops = v[1], current_city = v[2];
            pq.pop();
            if (stops > visited[current_city] || stops > k + 1)
                continue;
            visited[current_city] = stops;
            if (current_city == dst)
                return total_price;
            for (const auto& [to_city, price]: adj[current_city])
                pq.emplace(vector<int>{total_price + price, stops + 1, to_city});
        }

        return -1;
    }
};
