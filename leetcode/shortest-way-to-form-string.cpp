// 1055. Shortest Way to Form String
// https://leetcode.com/problems/shortest-way-to-form-string/

#include <bits/stdc++.h>

using namespace std;


// SLOW
// Based on Leetcode's Approach 2: Concatenate until Subsequence
class Solution {
public:
    int shortestWay(string source, string target) {
        vector<bool> chars(26);
        for (const char& ch: source) chars[ch - 'a'] = true;
        for (const char& ch: target) {
            if (!chars[ch - 'a']) return -1;
        }

        int ans = 1;
        string candidate = source;
        while (!IsSubsequence(target, candidate)) {
            candidate += source;
            ++ans;
        }

        return ans;
    }
private:
    // My own code from https://leetcode.com/problems/is-subsequence/submissions/913280311/
    bool IsSubsequence(string s, string t) {
        size_t s_len = s.size(), t_len = t.size();
        size_t s_idx = 0, t_idx = 0;
        while (s_idx < s_len) {
            while (t_idx < t_len && t[t_idx] != s[s_idx]) ++t_idx;
            if (t_idx == t_len) return false;
            ++s_idx;
            ++t_idx;
        }
        return s_idx == s_len ? true : false;
    }
};
