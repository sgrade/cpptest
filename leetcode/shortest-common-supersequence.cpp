// 1092. Shortest Common Supersequence
// https://leetcode.com/problems/shortest-common-supersequence/

#include <bits/stdc++.h>

using namespace std;


// MLE
// Approach 3: Bottom-Up Dynamic Programming
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n1 = str1.size(), n2 = str2.size();
        vector<string> prev_row(n2 + 1);
        for (int i2 = 0; i2 <= n2; ++i2)
            prev_row[i2] = str2.substr(0, i2);
        for (int i1 = 1; i1 <= n1; ++i1) {
            vector<string> cur_row(n2 + 1);
            cur_row[0] = str1.substr(0, i1);
            for (int i2 = 1; i2 <= n2; ++i2) {
                if (str1[i1 - 1] == str2[i2 - 1])
                    cur_row[i2] = prev_row[i2 - 1] + str1[i1 - 1];
                else {
                    string s1 = prev_row[i2];
                    string s2 = cur_row[i2 - 1];
                    cur_row[i2] = (s1.size() < s2.size()) ? s1 + str1[i1 - 1] : s2 + str2[i2 - 1];
                }
            }
            prev_row = cur_row;
        }
        return prev_row[n2];
    }
};
