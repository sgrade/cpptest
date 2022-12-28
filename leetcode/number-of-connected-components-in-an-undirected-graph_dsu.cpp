// 323. Number of Connected Components in an Undirected Graph
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 2: Disjoint Set Union (DSU)
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> representatives(n), territory_size(n, 1);
        for (int i = 0; i < n; ++i) {
            representatives[i] = i;
        }

        int components = n;
        for (const vector<int>& edge: edges) {
            components -= Combine(representatives, territory_size, edge[0], edge[1]);
        }

        return components;
    }

private:
    int Combine(vector<int>& representatives, vector<int>& territory_size, int vertex1, int vertex2) {
        int representative1 = FindRepresentative(representatives, vertex1);
        int representative2 = FindRepresentative(representatives, vertex2);
        if (representative1 == representative2) {
            return 0;
        }

        else {
            if (territory_size[representative1] > territory_size[representative2]) {
                territory_size[representative1] += territory_size[representative2];
                representatives[representative2] = representative1;
            }
            else {
                territory_size[representative2] += territory_size[representative1];
                representatives[representative1] = representative2;
            }
        }

        return 1;
    }

    int FindRepresentative(vector<int>& representatives, const int vertex) {
        if (vertex != representatives[vertex]) {
            representatives[vertex] = FindRepresentative(representatives, representatives[vertex]);
        }
        return representatives[vertex];
    }
};
