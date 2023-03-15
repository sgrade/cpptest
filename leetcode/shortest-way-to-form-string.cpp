// 1055. Shortest Way to Form String
// https://leetcode.com/problems/shortest-way-to-form-string/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 4: Inverted Index and Binary Search
class Solution {
public:
    int shortestWay(string source, string target) {
        vector<bool> chars(26);
        for (const char& ch: source) chars[ch - 'a'] = true;
        for (const char& ch: target) {
            if (!chars[ch - 'a']) return -1;
        }

        int ans = 1;

        size_t s_len = source.size(), t_len = target.size();
        size_t s_idx = 0, t_idx = 0;

        vector<vector<int>> indexes(26, vector<int>());
        for (size_t si = 0; si < s_len; ++si) 
            indexes[source[si] - 'a'].emplace_back(si);

        for (size_t ti = 0; ti < t_len; ++ti) {
            t_idx = target[ti] - 'a';
            s_idx = lower_bound(indexes[t_idx].begin(), indexes[t_idx].end(), s_idx) - indexes[t_idx].begin();
            if (s_idx == indexes[t_idx].size()) {
                ++ans;
                s_idx = indexes[t_idx][0] + 1;
            }
            else 
                s_idx = indexes[t_idx][s_idx] + 1;
        }
        
        return ans;
    }
};
