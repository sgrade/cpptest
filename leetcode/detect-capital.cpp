// 520. Detect Capital
// https://leetcode.com/problems/detect-capital/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool detectCapitalUse(string word) {
        int count_capital = isupper(word[0]) ? 1 : 0;
        for (int i = 1; i < word.size(); ++i) {
            if (isupper(word[i])) {
                ++count_capital;
            }
        }
        if ((count_capital == 1 && !isupper(word[0])) 
            || (count_capital > 1 && count_capital != word.size())) {
                return false;
        }
        return true;
    }
};
