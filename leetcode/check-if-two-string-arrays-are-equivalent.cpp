// 1662. Check If Two String Arrays are Equivalent
// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#include <bits/stdc++.h>

using namespace std;


// NOT FINISHED
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = -1, n2 = word2.size();
        for (const string& s: word1) {
            for (const char& ch: s) {
                ++j;
                if (i == n2 && j == -1)
                    return false;
                if (ch != word2[i][j])
                    return false;
                if (j == word2[i].size() - 1) {
                    ++i;
                    j = -1;
                }
            }
        }
        if (i != n2 - 1 && j != -1)
            return false;
        return true;
    }
};
