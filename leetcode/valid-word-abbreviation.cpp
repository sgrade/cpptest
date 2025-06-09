// 408. Valid Word Abbreviation
// https://leetcode.com/problems/valid-word-abbreviation/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int w_idx = 0, abbr_idx = 0, w_n = word.size(), abbr_n = abbr.size();
        while (abbr_idx < abbr_n) {
            bool d = isdigit(abbr[abbr_idx]);
            if (d) {
                int w_len = abbr[abbr_idx] - 48;
                if (w_len == 0)
                    return false;
                int j = abbr_idx + 1;
                while (j < abbr_n && isdigit(abbr[j])) {
                    w_len *= 10;
                    w_len += abbr[j++] - 48;
                }
                w_idx += w_len;
                abbr_idx = j;
                if (w_idx > w_n)
                    return false;
                if (w_idx == w_n)
                    return abbr_idx == abbr_n;
                if (word[w_idx] != abbr[abbr_idx])
                    return false;
            }
            else {
                if (word[w_idx++] != abbr[abbr_idx++])
                    return false;
            }
        }
        return w_idx == w_n && abbr_idx == abbr_n;
    }
};
