// 506. Relative Ranks
// https://leetcode.com/problems/relative-ranks/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = score.size();
        vector<pair<int, int>> score_with_idx(n);
        for (int i = 0; i < n; ++i) {
            score_with_idx[i].first = score[i];
            score_with_idx[i].second = i;
        }
        sort(score_with_idx.begin(), score_with_idx.end(), greater<pair<int, int>>());
        vector<string> ans(n);
        int i = 1;
        for (const auto& [score, idx]: score_with_idx) {
            if (i > 3)
                ans[idx] = to_string(i);
            else if (i == 1)
                ans[idx] = "Gold Medal";
            else if (i == 2)
                ans[idx] = "Silver Medal";
            else
                ans[idx] = "Bronze Medal";
            ++i;
        }
        return ans;
    }
};
