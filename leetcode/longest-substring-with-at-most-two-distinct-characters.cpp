// 159. Longest Substring with At Most Two Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

#include <bits/stdc++.h>

using namespace std;


// Optimized with ideas from sample 7ms solution
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size(), ans = 1;
        int left = 0, right = 0, cnt = 0;
        vector<int> idxs(58);
        while (right < n) {
            if (cnt == 3) {
                ans = max(ans, right - left - 1);
                // If there are no such chars to the left
                int idx = s[left] - 'A';
                cnt -= --idxs[idx] == 0;
                ++left;
            }
            else {
                int idx = s[right] - 'A';
                cnt += ++idxs[idx] == 1;
                ++right;
            }
        }
        return max(ans, right - left - (cnt == 3));
    }
};
