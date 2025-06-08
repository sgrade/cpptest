// 821. Shortest Distance to a Character
// https://leetcode.com/problems/shortest-distance-to-a-character/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = s.size();
        vector<int> ans(n, 1e5);
        int i = 0;
        while (i < n) {
            int c_idx = s.find(c, i);
            if (c_idx == string::npos)
                break;
            int j = i;
            for (; j <= c_idx; ++j)
                ans[j] = c_idx - j;
            i = j;
        }
        i = n - 1;
        while (i >= 0) {
            int c_idx = s.rfind(c, i);
            if (c_idx == string::npos)
                break;
            int j = i;
            for (; j >= c_idx; --j)
                ans[j] = min(ans[j], j - c_idx);
            i = j;
        }
        return ans;
    }
};
