// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int end_pos = s.size() - 1;
        while (end_pos >= 0 && s[end_pos] == ' ') {
            --end_pos;
        }
        int start_pos = end_pos;
        while (start_pos >= 0 && s[start_pos] != ' ') {
            --start_pos;
        }
        return end_pos - start_pos;
    }
};
