// 1371. Find the Longest Substring Containing Vowels in Even Counts
// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Bitmasking
class Solution {
public:
    int findTheLongestSubstring(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int prefix_xor = 0;
        vector<int> chars(26);
        chars['a' - 'a'] = 1;
        chars['e' - 'a'] = 2;
        chars['i' - 'a'] = 4;
        chars['o' - 'a'] = 8;
        chars['u' - 'a'] = 16;

        vector<int> mp(32, -1);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            prefix_xor ^= chars[s[i] - 'a'];
            if (mp[prefix_xor] == -1 && prefix_xor != 0)
                mp[prefix_xor] = i;
            ans = max(ans, i - mp[prefix_xor]);
        }
        return ans;
    }
};
