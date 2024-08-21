// 664. Strange Printer
// https://leetcode.com/problems/strange-printer/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Top Down Dynamic Programming (Memoization)
class Solution {
public:
    int strangePrinter(string s) {
        n = s.size();
        s = RemoveDuplicates(s);
        n = s.size();
        memo.resize(n, vector<int>(n, -1));
        return GetTurns(0, n - 1, s);
    }

private:
    int n;
    vector<vector<int>> memo;

    string RemoveDuplicates (string& s) {
        string uniq;
        int i = 0;
        while (i < n) {
            char current = s[i];
            uniq += current;
            while (i < n && s[i] == current)
                ++i;
        }
        return uniq;
    }

    int GetTurns (int left, int right, string& s) {
        if (left > right)
            return 0;
        if (memo[left][right] != -1)
            return memo[left][right];
        int min_turns = 1 + GetTurns(left + 1, right, s);
        for (int k = left + 1; k <= right; ++k) {
            if (s[k] == s[left]) {
                int turns_with_match = GetTurns(left, k - 1, s) + GetTurns(k + 1, right, s);
                min_turns = min(min_turns, turns_with_match);
            }
        }
        return memo[left][right] = min_turns;
    }
};
