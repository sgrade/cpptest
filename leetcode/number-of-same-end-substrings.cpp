// 2955. Number of Same-End Substrings
// https://leetcode.com/problems/number-of-same-end-substrings/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 2: Prefix Sum
class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = s.size();
        vector<vector<int>> counter(26, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            int char_idx = s[i] - 'a';
            ++counter[char_idx][i];
        }
        // prefix sum
        for (vector<int>& counts: counter) {
            for (int i = 1; i < n; ++i)
                counts[i] += counts[i - 1];
        }

        vector<int> ans;
        for (const vector<int>& query: queries) {
            int left_idx = query[0], right_idx = query[1];
            int current_ans = 0;
            for (int char_idx = 0; char_idx < 26; ++char_idx) {
                int left_freq = (left_idx == 0) ? 0 : counter[char_idx][left_idx - 1];
                int right_freq = counter[char_idx][right_idx];
                int freqs = right_freq - left_freq;
                current_ans += freqs * (freqs + 1) / 2;
            }
            ans.emplace_back(current_ans);
        }
        return ans;
    }
};
