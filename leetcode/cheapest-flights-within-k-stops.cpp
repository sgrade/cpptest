// 787. Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <bits/stdc++.h>

using namespace std;


// Time Limit Exceeded
// 47 / 54 testcases passed
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& f: flights) {
            int from_city = f[0], to_city = f[1], price = f[2];
            adj[from_city].emplace_back(to_city, price);
        }

        // {total_price, stops_left, to_city}
        priority_queue<
            vector<int>, vector<vector<int>>, greater<vector<int>>
            > pq;

        for (const auto& [to_city, price]: adj[src])
            pq.emplace(vector<int>{price, k, to_city});

        while (!pq.empty()) {
            auto& v = pq.top();
            int total_price = v[0], stops_left = v[1], current_city = v[2];
            pq.pop();
            if (current_city == dst)
                return total_price;
            if (stops_left > 0) {
                for (const auto& [to_city, price]: adj[current_city])
                    pq.emplace(vector<int>{total_price + price, stops_left - 1, to_city});
            }
        }

        return -1;
    }
};
