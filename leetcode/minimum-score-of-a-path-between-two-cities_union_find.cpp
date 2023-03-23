// 2492. Minimum Score of a Path Between Two Cities
// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 3: Union-find
class UnionFind {
public:
    UnionFind (int size): parent(size), rank(size) {
        for (int i = 0; i < size; ++i) parent[i] = i;
    }

    int Find (int x) {
        if (parent[x] != x) parent[x] = Find(parent[x]);
        return parent[x];
    }

    void UnionSet (int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset == yset) return;
        else if (rank[xset] < rank[yset])
            parent[xset] = yset;
        else if (rank[xset] > rank[yset])
            parent[yset] = xset;
        else {
            parent[yset] = xset;
            ++rank[xset];
        }
    }

private:
    vector<int> parent, rank;
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = numeric_limits<int>::max();
        UnionFind dsu (n + 1);
        for (const vector<int>& road: roads)
            dsu.UnionSet(road[0], road[1]);
        int dsu_find_one = dsu.Find(1);
        for (const vector<int>& road: roads) {
            if (dsu_find_one == dsu.Find(road[0]))
                ans = min(ans, road[2]);
        }
        return ans;
    }
};
