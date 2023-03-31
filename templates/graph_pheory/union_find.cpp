#include <bits/stdc++.h>

using namespace std;


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
            parent[root_x] = root_y;
            ++rank[root_y];
        }
    }
    bool Connected (int x, int y) {
        return Find(x) == Find(y);
    }
    vector<int> parent, rank;
};
