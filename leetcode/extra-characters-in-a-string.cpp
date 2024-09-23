// 2707. Extra Characters in a String
// https://leetcode.com/problems/extra-characters-in-a-string/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's pproach 1: Top Down Dynamic Programming with Substring Method
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        dict.insert(dictionary.begin(), dictionary.end());
        n = s.size();
        dp(0, s);
        return memo[0];
    }

private:
    int n;
    unordered_set<string> dict;
    unordered_map<int, int> memo;
    int dp(int left, const string& s) {
        if (left == n)
            return 0;
        if (memo.find(left) != memo.end())
            return memo[left];
        int ans = dp(left + 1, s) + 1;
        for (int right = left; right < n; ++right) {
            string new_s = s.substr(left, right - left + 1);
            if (dict.find(new_s) != dict.end())
                ans = min(ans, dp(right + 1, s));
        }
        return memo[left] = ans;
    }
};
