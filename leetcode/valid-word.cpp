// 3136. Valid Word
// https://leetcode.com/problems/valid-word/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isValid(string word) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        if (word.size() < 3)
            return false;
        bool vowel = false, consonant = false;
        for (const char& ch: word) {
            if (!isalnum(ch))
                return false;
            if (vowels.count(ch))
                vowel = true;
            else if (isalpha(ch))
                consonant = true;
        }
        return vowel && consonant;
    }
private:
    std::unordered_set<char> vowels = {'a','A','e','E','i','I','o','O','u','U'};
};
