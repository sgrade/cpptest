// 2000. Reverse Prefix of Word
// https://leetcode.com/problems/reverse-prefix-of-word/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int pos = 0;
        for (; pos < n; ++pos) {
            if (word[pos] == ch)
                break;
        }
        if (pos != n)
            reverse(word.begin(), word.begin() + pos + 1);
        return word;
    }
};
