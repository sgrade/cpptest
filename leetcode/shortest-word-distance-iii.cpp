// 245. Shortest Word Distance III
// https://leetcode.com/problems/shortest-word-distance-iii/

#include <bits/stdc++.h>

using namespace std;


// An idea is from https://leetcode.com/problems/shortest-word-distance-iii/solutions/67097/12-16-lines-java-c/
class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = wordsDict.size();
        int idx1 = n, idx2 = -n;
        int ans = n;
        bool same = word1 == word2;
        for (int i = 0; i < n; ++i) {
            if (wordsDict[i] == word1) {
                idx1 = i;
                if (same)
                    swap(idx1, idx2);
            }
            else if (wordsDict[i] == word2) {
                idx2 = i;
            }
            ans = min(ans, abs(idx1 - idx2));
        }
        return ans;
    }
};
