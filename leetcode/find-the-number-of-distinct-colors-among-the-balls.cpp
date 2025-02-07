// 3160. Find the Number of Distinct Colors Among the Balls
// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

#include <bits/stdc++.h>

using namespace std;


// Memory Limit Exceeded 547 / 551 testcases passed
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = queries.size();
        vector<int> balls(limit + 1), ans(n);
        balls[queries[0][0]] = queries[0][1], ans[0] = 1;
        unordered_map<int, int> colors;
        ++colors[queries[0][1]];

        for (int i = 1; i < n; ++i) {
            int ball = queries[i][0], color = queries[i][1];
            if (balls[ball] == color) {
                ans[i] = ans[i - 1];
                continue;
            }

            int prev_color = balls[ball];
            if (prev_color != 0) {
                --colors[prev_color];
                if (colors[prev_color] == 0)
                    colors.erase(prev_color);
            }
            ++colors[color];
            balls[ball] = color;
            ans[i] = colors.size();
        }

        return ans;
    }
};
