// 1930. Unique Length-3 Palindromic Subsequences
// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> indexes(26);
        for (int i = 0; i < s.size(); ++i) {
            indexes[s[i] - 'a'].emplace_back(i);
        }
        int ans = 0;
        for (const vector<int>& v: indexes) {
            if (v.size() < 2)
                continue;
            if (v.size() > 2)
                ++ans;
            vector<bool> used(26);
            for (int i = 1; i < v.size(); ++i) {
                if (v[i] - v[i - 1] == 1)
                    continue;
                for (int j = v[i - 1] + 1; j < v[i]; ++j)
                    used[s[j] - 'a'] = true;
            }
            ans += count(used.begin(), used.end(), true);
        }
        return ans;
    }
};
