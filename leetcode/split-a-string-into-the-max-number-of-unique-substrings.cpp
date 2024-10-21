// 1593. Split a String Into the Max Number of Unique Substrings
// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Backtracking
class Solution {
public:
    int maxUniqueSplit(string s) {
        return Backtrack(s, 0);
    }
private:
    unordered_set<string> seen;
    int Backtrack(const string& s, int left) {
        if (left == s.size())
            return 0;
        int ans = 0;
        for (int right = left + 1; right <= s.size(); ++right) {
            string subs = s.substr(left, right - left);
            if (seen.find(subs) == seen.end()) {
                seen.emplace(subs);
                ans = max(ans, 1 + Backtrack(s, right));
                seen.erase(subs);
            }
        }
        return ans;
    }
};
