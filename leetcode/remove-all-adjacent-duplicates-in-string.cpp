// 1047. Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Stack
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for (const char& ch: s) {
            if (!ans.empty() && ch == ans.back())
                ans.pop_back();
            else
                ans += ch;
        }
        return ans;
    }
};
