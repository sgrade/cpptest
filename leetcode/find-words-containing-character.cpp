// 2942. Find Words Containing Character
// https://leetcode.com/problems/find-words-containing-character/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].find(x) != string::npos)
                ans.emplace_back(i);
        }
        return ans;
    }
};
