// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans, need_counter(26), have_counter(26);

        int s_size, p_size;
        s_size = s.size(), p_size = p.size();
        if (s_size < p_size || s_size == 0) return ans;

        int ch_idx;
        int right = 0, left = 0, have, need;

        need = 0, have = 0;
        for (const char& ch: p) {
            ch_idx = ch - 'a';
            ++need_counter[ch_idx];
        }
        need = 26 - count(need_counter.begin(), need_counter.end(), 0);

        for (; right < s_size; ++right) {
            ch_idx = s[right] - 'a';
            ++have_counter[ch_idx];
            if (have_counter[ch_idx] == need_counter[ch_idx]) {
                ++have;
            }

            left = right - p.size() + 1;
            if (have == need)
                ans.emplace_back(left);
                
            if (left >= 0) {
                ch_idx = s[left] - 'a';
                if (have_counter[ch_idx] == need_counter[ch_idx])
                    --have;
                --have_counter[ch_idx];
            }
        }
        return ans;
    }
};
