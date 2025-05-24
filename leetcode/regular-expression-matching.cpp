// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        ss = s.size(), ps = p.size();
        memo.resize(ss + 1, vector<int>(ps + 1, -1));
        return dp(0, 0, s, p);
    }

private:
    int ss, ps;
    vector<vector<int>> memo;
    bool dp (int s_idx , int p_idx, string s, string p) {
        if (memo[s_idx][p_idx] != -1)
            return memo[s_idx][p_idx];

        bool ans;
        if (p_idx == ps)
            ans = s_idx == ss;
        else {
            bool first_match = (
                s_idx < ss &&
                (p[p_idx] == s[s_idx] || p[p_idx] == '.')
            );
            if (p_idx + 1 < ps && p[p_idx + 1] == '*')
                ans = dp(s_idx, p_idx + 2, s, p) || (first_match && dp(s_idx + 1, p_idx, s, p));
            else
                ans = first_match && dp(s_idx + 1, p_idx + 1, s, p);
        }

        memo[s_idx][p_idx] = ans;
        return ans;
    }
};
