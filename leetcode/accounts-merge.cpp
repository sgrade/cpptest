// 721. Accounts Merge
// https://leetcode.com/problems/accounts-merge/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adj;
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Adjacencies
        for (vector<string> &account: accounts) {
            for (int i = 2; i < account.size(); ++i) {
                adj[account[1]].push_back(account[i]);
                adj[account[i]].push_back(account[1]);
            }
        }
        
        // Merging
        vector<vector<string>> merged;
        for (vector<string>& account: accounts) {
            if (visited.find(account[1]) != visited.end()) {
                continue;
            }
            vector<string> current;
            current.push_back(account[0]);
            dfs(current, account[1]);
            sort(current.begin() + 1, current.end());
            merged.push_back(current);
        }
        return merged;
    }
    
    void dfs(vector<string>& current, string &email) {
        visited.insert(email);
        current.push_back(email);
        for (string &neighbor: adj[email]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(current, neighbor);
            }
        }
    }
};
