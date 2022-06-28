// 159. Longest Substring with At Most Two Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() < 3) return s.size();
        int ans = 2;
        map<char, int> chars;
        int left = 0, right = 0;
        while (right < s.size()) {
            chars[s[right]] = right;
            ++right;
            if (chars.size() == 3) {
                int idx = s.size();
                for (const auto &[key, value]: chars) {
                    idx = min(idx, value);
                }
                chars.erase(s[idx]);
                left = idx + 1;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};
