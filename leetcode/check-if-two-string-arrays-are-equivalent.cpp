// 1662. Check If Two String Arrays are Equivalent
// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#include <bits/stdc++.h>

using namespace std;


// Optimized with Editorial's Approach 2: Two Pointers
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
        int n1 = word1.size(), n2 = word2.size();
        while (i1 < n1 && i2 < n2) {
            if (word1[i1][j1++] != word2[i2][j2++])
                return false;
            if (j1 == word1[i1].size()) {
                ++i1;
                j1 = 0;
            }
            if (j2 == word2[i2].size()) {
                ++i2;
                j2 = 0;
            }
        }
        return i1 == n1 && i2 == n2;
    }
};
