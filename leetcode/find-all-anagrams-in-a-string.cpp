// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <bits/stdc++.h>

using namespace std;


// SLOW
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> need_counter, have_counter;

        int s_size, p_size;
        s_size = s.size(), p_size = p.size();
        if (s_size < p_size || s_size == 0) return ans;

        char ch;
        int right = 0, left = 0, have, need;

        need = 0, have = 0;
        for (const char& ch: p) {
            ++need_counter[ch];
        }
        need = need_counter.size();

        for (; right < s_size; ++right) {
            ch = s[right];
            ++have_counter[ch];
            if (have_counter[ch] == need_counter[ch]) {
                ++have;
            }
            if (need_counter.find(ch) == need_counter.end()) {
                have = 0;
                have_counter.clear();
                continue;
            }

            left = right - p.size() + 1;
            if (have == need)
                ans.emplace_back(left);
                
            if (left >= 0) {
                if (have_counter[s[left]] == need_counter[s[left]])
                    --have;
                --have_counter[s[left]];
            }
        }
        return ans;
    }
};
