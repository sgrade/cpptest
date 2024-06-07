// 1791. Find Center of Star Graph
// https://leetcode.com/problems/find-center-of-star-graph/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        return edges[0][1];
    }
};
