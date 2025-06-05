// 1061. Lexicographically Smallest Equivalent String
// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

#include <bits/stdc++.h>

using namespace std;


// Used ideas from Editorial's Approach 2: Disjoint Set Union (DSU/Union Find)

class UnionFind {
public:
    UnionFind (int size): parent(size) {
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
        if (root_x < root_y)
            parent[root_y] = root_x;
        else
            parent[root_x] = root_y;
    }
    vector<int> parent;
};


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        UnionFind dsu(26);
        for (int i = 0; i < s1.size(); ++i)
            dsu.UnionSet(s1[i] - 'a', s2[i] - 'a');
        string ans = baseStr;
        for (int i = 0; i < baseStr.size(); ++i) {
            int idx = dsu.Find(ans[i] - 'a');
            char cur = 'a' + idx;
            ans[i] = cur;
        }
        return ans;
    }
};
