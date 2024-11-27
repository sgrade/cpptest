// 3243. Shortest Distance After Road Addition Queries I
// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Iterative Dynamic Programming (Bottom-Up)
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->n = n;
        vector<int> ans;
        adj.resize(n);
        for (int i = 0; i < n - 1; ++i)
            adj[i].emplace_back(i + 1);
        for (const vector<int>& query: queries) {
            int source = query[0], destination = query[1];
            adj[source].emplace_back(destination);
            int min_distance = getDistance();
            ans.emplace_back(min_distance);
        }
        return ans;
    }
private:
    int n;
    vector<vector<int>> adj;
    int getDistance() {
        vector<int> dp(n);
        dp[n - 1] = 0;
        for (int node = n - 2; node >= 0; --node) {
            int dist = n;
            for (const int& neighbor: adj[node])
                dist = min(dist, dp[neighbor] + 1);
            dp[node] = dist;
        }
        return dp[0];
    }
};
