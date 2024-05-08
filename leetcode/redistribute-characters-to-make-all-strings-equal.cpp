// 1897. Redistribute Characters to Make All Strings Equal
// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> counter(26);
        for (const string& word: words) {
            for (const char& ch: word)
                ++counter[ch - 'a'];
        }
        int n = words.size();
        for (const int& cnt: counter) {
            if (cnt % n != 0)
                return false;
        }
        return true;
    }
};
