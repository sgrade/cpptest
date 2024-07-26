// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 4: Floyd-Warshall Algorithm
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->n = n;
        distance.resize(n, vector<int>(n, 1e4 + 1));
        for (int i = 0; i < n; ++i)
            distance[i][i] = 0;
        for (const vector<int>& edge: edges) {
            int start = edge[0], end = edge[1], weight = edge[2];
            distance[start][end] = weight;
            distance[end][start] = weight;
        }

        FloydWarshall();

        int city = -1;
        int fewest_reachable = n;
        for (int i = 0; i < n; ++i) {
            int reachable = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                if (distance[i][j] <= distanceThreshold)
                    ++reachable;
            }
            if (reachable <= fewest_reachable) {
                fewest_reachable = reachable;
                city = i;
            }
        }
        return city;
    }

private:
    int n;
    vector<vector<int>> distance;

    void FloydWarshall () {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

};
