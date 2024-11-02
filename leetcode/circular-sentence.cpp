// 2490. Circular Sentence
// https://leetcode.com/problems/circular-sentence/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isCircularSentence(string sentence) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        istringstream iss(sentence);
        string tmp;
        iss >> tmp;
        string first_word = tmp;
        char first, last = first_word[first_word.size() - 1];
        while(iss >> tmp) {
            first = tmp[0];
            if (first != last)
                return false;
            last = tmp[tmp.size() - 1];
        }
        return first_word[0] == last;
    }
};
