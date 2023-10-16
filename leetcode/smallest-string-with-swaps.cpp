// 1202. Smallest String With Swaps
// https://leetcode.com/problems/smallest-string-with-swaps/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        n = s.size();
        adj.resize(n);
        visited.resize(n);

        for (const vector<int>& edge: pairs) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (visited[i])
                continue;
            vector<char> chars;
            vector<int> indexes;
            dfs(s, i, chars, indexes);
            sort(chars.begin(), chars.end());
            sort(indexes.begin(), indexes.end());
            for (int j = 0; j < indexes.size(); ++j)
                s[indexes[j]] = chars[j];
        }

        return s;
    }

private:
    int n;
    vector<vector<int>> adj;
    vector<bool> visited;

    void dfs(const string& s, const int& i, vector<char>& chars, vector<int>& indexes) {
        chars.emplace_back(s[i]);
        indexes.emplace_back(i);
        visited[i] = true;
        for (const int& neighbor: adj[i]) {
            if (visited[neighbor])
                continue;
            dfs(s, neighbor, chars, indexes);
        }
    }
};
