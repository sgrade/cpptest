// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <bits/stdc++.h>

using namespace std;


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
            while (right < s_size && right < left + p_size - 1) {
                ch = s[right];
                if (need_counter.find(ch) == need_counter.end()) {
                    have = 0;
                    have_counter.clear();
                    left = right + 1;
                    continue;
                }
                ++have_counter[ch];
                if (have_counter[ch] == need_counter[ch]) {
                    ++have;
                }
            }
            
            left = right - p_size + 1;
            if (have == need)
                ans.emplace_back(left);
                
            if (have_counter[left] == need_counter[left])
                --have;
            --have_counter[s[left]];
        }
        return ans;
    }
};
