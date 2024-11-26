// 2924. Find Champion II
// https://leetcode.com/problems/find-champion-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: In-degree Count
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> indegree(n, 0);
        for (const vector<int>& edge: edges)
            ++indegree[edge[1]];
        int champion = -1, champions = 0;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                ++champions;
                champion = i;
            }
        }
        return champions > 1 ? -1 : champion;
    }
};
