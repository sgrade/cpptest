// 305. Number of Islands II
// https://leetcode.com/problems/number-of-islands-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Union Find
class UnionFind {
public:
    UnionFind (int size): rank(size) {
        parent.resize(size, -1);
        count = 0;
    }
    void addLand (int x) {
        if (parent[x] >= 0)
            return;
        parent[x] = x;
        ++count;
    }
    bool isLand (int x) {
        if (parent[x] >= 0)
            return true;
        return false;
    }
    int numberOfIslands () {
        return count;
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
        --count;
    }
    bool Connected (int x, int y) {
        return Find(x) == Find(y);
    }
    vector<int> parent, rank;
    int count;
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        UnionFind dsu(m * n);
        vector<int> ans;

        for (const auto& p: positions) {
            int land_position = p[0] * n + p[1];
            dsu.addLand(land_position);
            for (int i = 0; i < 4; ++i) {
                int neighbor_x = p[0] + x[i];
                int neighbor_y = p[1] + y[i];
                int neighbor_position = neighbor_x * n + neighbor_y;
                if (
                    neighbor_x >= 0 && neighbor_x < m &&
                    neighbor_y >= 0 && neighbor_y < n &&
                    dsu.isLand(neighbor_position)
                    ){
                        dsu.UnionSet(land_position, neighbor_position);
                    }
            }
            ans.emplace_back(dsu.numberOfIslands());
        }

        return ans;
    }

private:
    int rows, cols;
    vector<int> x = {-1, 1, 0, 0}, y = {0, 0, -1, 1};
};
