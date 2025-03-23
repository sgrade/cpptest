// 2685. Count the Number of Complete Components
// https://leetcode.com/problems/count-the-number-of-complete-components/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 4: Disjoint Set Union (Union-Find)
class UnionFind {
    public:
        vector<int> parent, rank;
        UnionFind (int n): parent(n, -1), rank(n, 1) {}

        int Find (int x) {
            if (parent[x] == -1)
                return x;
            return parent[x] = Find(parent[x]);
        }

        void UnionSet(int x, int y) {
            int root_x = Find(x), root_y = Find(y);
            if (root_x == root_y)
                return;
            if (rank[root_x] > rank[root_y]) {
                parent[root_y] = root_x;
                rank[root_x] += rank[root_y];
            }
            else {
                parent[root_x] = root_y;
                rank[root_y] += rank[root_x];
            }
        }
    };

    class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            UnionFind dsu(n);
            for (const vector<int>& e: edges)
                dsu.UnionSet(e[0], e[1]);

            unordered_map<int, int> edges_in_component;  // {root, count}
            for (const vector<int>& e: edges) {
                int root = dsu.Find(e[0]);
                ++edges_in_component[root];
            }

            int ans = 0;
            for (int vertex = 0; vertex < n; ++vertex) {
                if (dsu.Find(vertex) == vertex) {
                    int nodes = dsu.rank[vertex];
                    int need = (nodes * (nodes - 1)) / 2;
                    if (edges_in_component[vertex] == need)
                        ++ans;
                }
            }
            return ans;
        }
    };
