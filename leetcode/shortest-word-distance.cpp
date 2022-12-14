// 243. Shortest Word Distance
// https://leetcode.com/problems/shortest-word-distance/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        int idx1 = -1, idx2 = -1;
        int i = 0;
        while (idx1 == -1 || idx2 == -1) {
            if (idx1 == -1 && wordsDict[i] == word1) idx1 = i;
            else if (idx2 == -1 && wordsDict[i] == word2) idx2 = i;
            ++i;
        }
        int ans = abs(idx1 - idx2);
        for (i = min(idx1, idx2) + 1; i < n; ++i) {
            if (wordsDict[i] == word1) idx1 = i;
            else if (wordsDict[i] == word2) idx2 = i;
            else continue;
            ans = min(ans, abs(idx1 - idx2));
        }
        return ans;
    }
};
