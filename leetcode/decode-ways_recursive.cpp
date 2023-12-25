// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Recursive Approach with Memoization
class Solution {
public:
    int numDecodings(string s) {
        n = s.size();
        return dfs(s, 0);
    }
private:
    int n;
    map<int, int> memo;
    int dfs (const string& s, int i) {
        if (memo.find(i) != memo.end())
            return memo[i];
        if (i == n)
            return 1;
        if (s[i] == '0')
            return 0;
        if (i == n - 1)
            return 1;
        int ans = dfs(s, i + 1);
        if (stoi(s.substr(i, 2)) < 27)
            ans += dfs(s, i + 2);
        memo[i] = ans;
        return ans;
    }
};
