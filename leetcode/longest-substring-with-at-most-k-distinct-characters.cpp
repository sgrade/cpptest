// 340. Longest Substring with At Most K Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;
        if (k == 0) return ans;
        int n = s.size();
        unordered_map<char, int> mp;
        int left = 0, right = 0;
        while (right < n) {
            mp[s[right]] = right;
            ++right;
            if (mp.size() > k) {
                left = INT_MAX;
                for (const auto &[ch, index] : mp) {
                    left = min(left, index);
                }
                mp.erase(s[left]);
                ++left;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};
