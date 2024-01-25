// 1143. Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 4: Dynamic Programming with Space Optimization
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        if (n2 < n1) {
            swap(n1, n2);
            swap(text1, text2);
        }
        vector<int> prev(n1 + 1);
        for (int i2 = n2 - 1; i2 >= 0; --i2) {
            vector<int> current(n1 + 1);
            for (int i1 = n1 - 1; i1 >= 0; --i1) {
                if (text1[i1] == text2[i2])
                    current[i1] = 1 + prev[i1 + 1];
                else
                    current[i1] = max(prev[i1], current[i1 + 1]);
            }
            prev = current;
        }
        return prev[0];
    }
};
