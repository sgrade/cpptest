// 1743. Restore the Array From Adjacent Pairs
// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        unordered_map<int, vector<int>> adj;
        for (const vector<int>& v: adjacentPairs) {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        vector<pair<int, int>> ends;
        auto it = adj.begin();
        while (it != adj.end()) {
            if (it->second.size() == 1) {
                ends.emplace_back(it->first, it->second[0]);
                adj.erase(it++);
                continue;
            }
            ++it;
        }

        vector<int> ans(n);
        ans[0] = ends[0].first;
        ans[n - 1] = ends[1].first;
        int prev = ends[0].first, current = ends[0].second, next;
        for (int i = 1; i < n - 1; ++i) {
            if (adj[current][0] != prev)
                next = adj[current][0];
            else
                next = adj[current][1];
            ans[i] = current;
            prev = current;
            current = next;
        }

        return ans;
    }
};
