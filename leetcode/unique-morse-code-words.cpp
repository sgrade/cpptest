// 804. Unique Morse Code Words
// https://leetcode.com/problems/unique-morse-code-words/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        unordered_set<string> transformed;
        for (const string& word: words) {
            string t;
            for (const char& ch: word)
                t += morse_code[ch - 'a'];
            transformed.emplace(t);
        }
        return (int)transformed.size();
    }
private:
    vector<string> morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
};
