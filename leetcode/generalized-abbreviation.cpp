// 320. Generalized Abbreviation
// https://leetcode.com/problems/generalized-abbreviation/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Backtracking
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        n = word.size();
        GetAbbreviations (word, "", 0, 0);
        return ans;
    }

private:
    int n;
    vector<string> ans;
    void GetAbbreviations (string& word, string current, int i, int cnt) {
        string s = cnt == 0 ? "" : to_string(cnt);
        if (i == n) {
            current += s;
            ans.emplace_back(current);
            return;
        }
        GetAbbreviations (word, current + s + word[i], i + 1, 0);
        GetAbbreviations (word, current, i + 1, cnt + 1);
    }
};
