// 1615. Maximal Network Rank
// https://leetcode.com/problems/maximal-network-rank/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> neighbors(n);
        vector<vector<bool>> connected(n, vector<bool>(n));
        for (const vector<int>& road: roads) {
            ++neighbors[road[0]];
            ++neighbors[road[1]];
            connected[road[0]][road[1]] = true;
            connected[road[1]][road[0]] = true;
        }
        
        int ans = 0, current_ans;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                current_ans = neighbors[i] + neighbors[j];
                if (connected[i][j])
                    --current_ans;
                ans = max(ans, current_ans);
            }
        }
        
        return ans;
    }
};
