// 1135. Connecting Cities With Minimum Cost
// https://leetcode.com/problems/connecting-cities-with-minimum-cost/

#include <vector>
#include <numeric>
#include <algorithm>

using std::vector;
using std::iota;
using std::sort;


// Based on Editorial's Connecting Cities With Minimum Cost
class UnionFind {
public:
    UnionFind (int size): parent(size), rank(size) {
        iota(parent.begin(), parent.end(), 0);
    }
    int Find (int x) {
        if (x != parent[x])
            parent[x] = Find(parent[x]);
        return parent[x];
    }
    void UnionSet (int x, int y) {
        int root_x = Find(x); 
        int root_y = Find(y);
        if (root_x == root_y)
            return;
        if (rank[root_x] < rank[root_y])
            parent[root_x] = root_y;
        else if (rank[root_y] < rank[root_x])
            parent[root_y] = root_x;
        else {
            parent[root_y] = root_x;
            ++rank[root_x];
        }
    }
    bool Connected (int x, int y) {
        return Find(x) == Find(y);
    }
    vector<int> parent, rank;
};


class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), 
            [](const vector<int>& v1, const vector<int>& v2){
                return v1[2] < v2[2];
            });
        UnionFind dsu(n + 1);
        int edges = 0, cost = 0;
        for (int i = 0; i < connections.size(); ++i) {
            int x = connections[i][0];
            int y = connections[i][1];
            if (dsu.Connected(x, y)) {
                continue;
            }
            dsu.UnionSet(x, y);
            ++edges;
            cost += connections[i][2];
        }
        return edges == n - 1 ? cost : -1;
    }
};
