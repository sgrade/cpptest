// 1615. Maximal Network Rank
// https://leetcode.com/problems/maximal-network-rank/

#include <bits/stdc++.h>

using namespace std;


// Memory Limit Exceeded
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for (const vector<int>& road: roads) {
            adj[road[0]].emplace_back(road[1]);
            adj[road[1]].emplace_back(road[0]);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(adj[0].size(), 0);
        pq.emplace(adj[1].size(), 1);
        for (int city = 2; city < n; ++city) {
            int connected_roads = adj[city].size();
            if (connected_roads < pq.top().first)
                continue;
            else if (connected_roads > pq.top().first)
                pq.pop();
            pq.emplace(connected_roads, city);
        }
        
        // There can be multiple cities with the same number of roads;
        int second_max_roads = pq.top().first;
        vector<int> second_max_cities;
        while (pq.top().first == second_max_roads) {
            second_max_cities.emplace_back(pq.top().second);
            pq.pop();
        }
        
        int max_roads = pq.top().first;
        int ans = max_roads + second_max_roads;
        
        while (!pq.empty()) {
            int max_city = pq.top().second;
            vector<int>& neighbors = adj[max_city];
            for (const int& city: second_max_cities) {
                if (find(neighbors.begin(), neighbors.end(), city) == neighbors.end())
                    return ans;
            }
            pq.pop();
        }
        
        return ans - 1;
    }
};
