// 1101. The Earliest Moment When Everyone Become Friends
// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/

#include <bits/stdc++.h>

using namespace std;


struct UnionFind {
    vector<int> parent, rank;
    UnionFind (int size): parent(size), rank(size) {
        iota(parent.begin(), parent.end(), 0);
    }
    int Find (int x) {
        if (parent[x] != x) {
            parent[x] = Find (parent[x]);
        }
        return parent[x];
    }
    int UnionSet (int x, int y) {
        int root_x = Find(x), root_y = Find(y);
        if (root_x == root_y)
            return 0;
        if (rank[root_x] < rank[root_y])
            parent[root_x] = root_y;
        else if (rank[root_y] < rank[root_x])
            parent[root_y] = root_x;
        else {
            parent[root_y] = root_x;
            ++rank[root_x];
        }
        return 1;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        UnionFind dsu(n);
        int sets = n;
        for (vector<int>& log: logs) {
            if (log[1] > log[2])
                swap(log[1], log[2]);
            sets -= dsu.UnionSet(log[1], log[2]);
            if (sets == 1)
                return log[0];
        }
        return -1;
    }
};
