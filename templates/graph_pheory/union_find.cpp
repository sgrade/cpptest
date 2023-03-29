#include <bits/stdc++.h>

using namespace std;


class UnionFind {
public:
    UnionFind (int size): parent(size), rank(size) {
        iota (parent.begin(), parent.end(), 0);
    }
    int Find (int x) {
        if (parent[x] != x)
            parent[x] = Find(parent[x]);
        return parent[x];
    }
    void UnionSet (int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset == yset)
            return;
        else if (rank[xset] < rank[yset])
            parent[xset] = yset;
        else if (rank[xset] > rank[yset])
            parent[yset] = xset;
        else {
            parent[yset] = xset;
            ++rank[xset];
        }
    }
    bool Connected (int x, int y) {
        return Find(x) == Find(y);
    }
private:
    vector<int> parent, rank;
};
