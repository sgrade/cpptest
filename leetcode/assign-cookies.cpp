// 455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int len_s = s.size(), len_g = g.size();
        for (int s_idx = 0, g_idx = 0; g_idx < len_g; ++g_idx, ++s_idx) {
            while (s_idx < len_s && s[s_idx] < g[g_idx]) ++s_idx;
            if (s_idx == len_s) break;
            ++ans;
        }
        return ans;
    }
};
