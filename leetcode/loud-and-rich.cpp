// 851. Loud and Rich
// https://leetcode.com/problems/loud-and-rich/

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        for (const vector<int>& r: richer) {
            adj[r[1]].emplace_back(r[0]);
        }
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);
        for (int person = 0; person < n; ++person) {
            vector<bool> visited(n, false);
            queue<int> q;
            q.emplace(person);
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                visited[current] = true;
                if (quiet[current] <= quiet[ans[person]]) {
                    ans[person] = current;
                }
                for (const int neighbor: adj[current]) {
                    if (visited[neighbor]) {
                        continue;
                    }
                    q.emplace(neighbor);
                }
            }
        }
        return ans;
    }
};
