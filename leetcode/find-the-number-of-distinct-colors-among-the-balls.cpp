// 3160. Find the Number of Distinct Colors Among the Balls
// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
    
            int n = queries.size();
            vector<int> ans(n);
            unordered_map<int, int> balls, colors;
    
            for (int i = 0; i < n; ++i) {
                int ball = queries[i][0], color = queries[i][1];
                if (balls[ball] != 0) {
                    int prev_color = balls[ball];
                    --colors[prev_color];
                    if (colors[prev_color] == 0)
                        colors.erase(prev_color);
                }
                balls[ball] = color;
                ++colors[color];
                ans[i] = colors.size();
            }
    
            return ans;
        }
    };
    
