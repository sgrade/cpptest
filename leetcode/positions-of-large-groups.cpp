// 830. Positions of Large Groups
// https://leetcode.com/problems/positions-of-large-groups/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int start = 0, end = 1;
        for (; end < s.size(); ++end) {
            if (s[start] != s[end]) {
                if (end - start > 2) {
                    ans.emplace_back(vector<int>{start, end - 1});
                }
                start = end;
            }
        }
        if (end == s.size() && end - start > 2)
            ans.emplace_back(vector<int>{start, end - 1});
        return ans;
    }
};
