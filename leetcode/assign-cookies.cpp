// 455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int len_s = s.size(), len_g = g.size();
        int s_idx = 0, g_idx = 0;
        // Optimized with Editorial's solution
        while (s_idx < len_s && g_idx < len_g) {
            if (s[s_idx] >= g[g_idx])
                ++g_idx;
            ++s_idx;
        }
        return g_idx;
    }
};
