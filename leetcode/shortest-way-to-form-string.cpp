// 1055. Shortest Way to Form String
// https://leetcode.com/problems/shortest-way-to-form-string/

#include <bits/stdc++.h>

using namespace std;


// Beats 32%
// Based on Leetcode's Approach 3: Two Pointers
class Solution {
public:
    int shortestWay(string source, string target) {
        vector<bool> chars(26);
        for (const char& ch: source) chars[ch - 'a'] = true;
        for (const char& ch: target) {
            if (!chars[ch - 'a']) return -1;
        }

        int ans = 0;
       
        size_t s_len = source.size(), t_len = target.size();
        size_t s_idx = 0, t_idx = 0;
        while (t_idx < t_len) {
            if (s_idx == 0)
                ++ans;
            while (source[s_idx++] != target[t_idx]) {
                s_idx %= s_len;
                // If we need to start from the beginning of the source
                if (s_idx == 0)
                    ++ans;
            }
            // If the chars are equal, the incremented s_idx not % in the loop, so we do it here
            s_idx %= s_len;
            ++t_idx;
        }

        return ans;
    }
};
