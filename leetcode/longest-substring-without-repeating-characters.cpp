// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {    
        
        int ans = 0;
        int n = s.size();
        
        unordered_map<char, int> mp;
        
        int left = 0, right = 0;
        char ch;
        for (; right < n; ++right) {
            ch = s[right];
            if (mp.find(ch) != mp.end()) left = max(left, mp[ch]);
            ans = max(ans, right - left + 1);
            mp[ch] = right + 1;
        }
        
        return ans;
    }
};
