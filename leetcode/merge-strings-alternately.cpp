// 1768. Merge Strings Alternately
// https://leetcode.com/problems/merge-strings-alternately/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        size_t i = 0, n1 = word1.size(), n2 = word2.size();
        while (i < n1 || i < n2) {
          if (i < n1)
            ans += word1[i];
          if (i < n2)
            ans += word2[i];
          ++i;
        }
        return ans;
    }
};
