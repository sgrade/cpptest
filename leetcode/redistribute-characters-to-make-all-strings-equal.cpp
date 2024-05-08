// 1897. Redistribute Characters to Make All Strings Equal
// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<int, int> counter;
        for (const string& word: words) {
            for (const char& ch: word)
                ++counter[ch];
        }
        int n = words.size();
        for (const auto& [_, cnt]: counter) {
            if (cnt % n != 0)
                return false;
        }
        return true;
    }
};
