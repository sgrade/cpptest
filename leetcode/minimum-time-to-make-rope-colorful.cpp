// 1578. Minimum Time to Make Rope Colorful
// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = 0;
        int n = colors.size();
        neededTime.emplace_back(0);
        colors += colors[n - 1] == 'a' ? 'b' : 'a';
        int sum = neededTime[0];
        int mx = neededTime[0];
        for (int i = 0; i < n; ++i) {
            if (colors[i] == colors[i + 1]) {
                sum += neededTime[i + 1];
                mx = max(mx, neededTime[i + 1]);
            }
            else {
                ans += sum - mx;
                sum = neededTime[i + 1];
                mx = neededTime[i + 1];
            }
        }
        return ans;
    }
};
