// 2109. Adding Spaces to a String
// https://leetcode.com/problems/adding-spaces-to-a-string/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Using Built-in Functions
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int idx = 0;
        stringstream ans;
        for (int i = 0; i < s.size(); ++i) {
            if (idx < spaces.size() && spaces[idx] == i) {
                ans << ' ';
                ++idx;
            }
            ans << s[i];
        }
        return ans.str();
    }
};
