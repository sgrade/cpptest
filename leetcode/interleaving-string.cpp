// 97. Interleaving String
// https://leetcode.com/problems/interleaving-string/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 2: Recursion with memoization
class Solution {
public:
    int n, m;
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size(), m = s2.size();
        if (n + m != s3.size()) {
            return false;
        }
        vector<vector<int>> processed(n, vector<int>(m, -1));
        return IsInterleave(s1, 0, s2, 0, s3, 0, processed);
    }

private:
    bool IsInterleave(const string &s1, int i, const string &s2, int j, const string &s3, int k, vector<vector<int>> &processed) {
        if (i == n) {
            return s2.substr(j) == s3.substr(k);
        }
        if (j == m) {
            return s1.substr(i) == s3.substr(k);
        }
        if (processed[i][j] >= 0) {
            return processed[i][j] == 1 ? true : false;
        }
        bool ans = false;
        if (s3[k] == s1[i] && IsInterleave(s1, i + 1, s2, j, s3, k + 1, processed) || 
            s3[k] == s2[j] && IsInterleave(s1, i, s2, j + 1, s3, k + 1, processed)) {
            ans = true;
        }
        processed[i][j] = ans ? 1 : 0;
        return ans;
    }
};
