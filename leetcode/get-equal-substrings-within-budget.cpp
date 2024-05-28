// 1208. Get Equal Substrings Within Budget
// https://leetcode.com/problems/get-equal-substrings-within-budget/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = s.size(), ans = 0;
        vector<int> costs(n);
        for (int i = 0; i < n; ++i)
            costs[i] = abs(s[i] - t[i]);

        int left = 0, right = 0, current_cost = 0;
        while (right < n) {
            current_cost += costs[right++];
            if (current_cost <= maxCost)
                ans = max(ans, right - left);
            while (left < right && current_cost > maxCost)
                current_cost -= costs[left++];
        }

        return ans;
    }
};
