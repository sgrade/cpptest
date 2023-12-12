// 2606. Find the Substring With Maximum Cost
// https://leetcode.com/problems/find-the-substring-with-maximum-cost/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> costs(26);
        iota(costs.begin(), costs.end(), 1);
        for (int i = 0; i < chars.size(); ++i)
            costs[chars[i] - 'a'] = vals[i];

        // Kadane's algorithm
        int ans = 0, sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            sum += costs[s[i] - 'a'];
            ans = max(ans, sum);
            if (sum < 0)
                sum = 0;
        }
        return ans;
    }
};
