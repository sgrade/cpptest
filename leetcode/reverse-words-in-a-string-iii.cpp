// 557. Reverse Words in a String III
// https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stringstream ss(s);
        string word;
        while (getline(ss, word, ' ')) {
            reverse(word.begin(), word.end());
            ans += word + ' ';
        }
        ans.pop_back();
        return ans;
    }
};
