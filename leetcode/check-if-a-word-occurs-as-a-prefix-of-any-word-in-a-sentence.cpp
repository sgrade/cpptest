// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string tmp;
        int ans = 1;
        while (getline(iss, tmp, ' ')) {
            size_t pos = tmp.find(searchWord);
            if (pos == 0)
                return ans;
            ++ans;
        }
        return -1;
    }
};
