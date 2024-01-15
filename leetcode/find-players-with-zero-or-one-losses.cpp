// 2225. Find Players With Zero or One Losses
// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        for (const vector<int>& v: matches) {
            losses[v[0]];
            ++losses[v[1]];
        }
        vector<vector<int>> ans(2);
        for (const auto& [player, cnt]: losses) {
            if (cnt == 0)
                ans[0].emplace_back(player);
            else if (cnt == 1)
                ans[1].emplace_back(player);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
