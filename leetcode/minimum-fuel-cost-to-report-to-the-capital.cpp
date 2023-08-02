// 2477. Minimum Fuel Cost to Report to the Capital
// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Depth First Search
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        n = roads.size() + 1;
        adj.resize(n);
        for (const vector<int>& road: roads) {
            adj[road[0]].emplace_back(road[1]);
            adj[road[1]].emplace_back(road[0]);
        }

        dfs(0, -1, seats);
        return fuel;
    }

private:
    int n;
    long long fuel;
    vector<vector<int>> adj;

    long long dfs (int node, int parent, int& seats) {
        int representatives = 1;
        for (const int& child: adj[node]) {
            if (child != parent)
                representatives += dfs(child, node, seats);
        }
        
        if (node != 0) 
            fuel += ceil((double)representatives / seats);

        return representatives;
    }
};
