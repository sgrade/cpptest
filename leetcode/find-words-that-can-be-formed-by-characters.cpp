// 1160. Find Words That Can Be Formed by Characters
// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> counter;
        for (const char& ch: chars)
            ++counter[ch];
        int ans = 0;
        for (const string& word: words) {
            unordered_map<char, int> current;
            for (const char& ch: word)
                ++current[ch];
            bool good = true;
            for (const auto& [ch, cnt]: current) {
                if (counter[ch] < cnt) {
                    good = false;
                    break;
                }
            }
            if (good)
                ans += word.size();
        }
        return ans;
    }
};
