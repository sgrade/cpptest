// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

#include <bits/stdc++.h>

using namespace std;


// Based on a fast sample solution
class Solution {
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> current;
        dfs (s, 0, current);
        return ans;
    }

private:
    int n;
    vector<vector<string>> ans;

    void dfs (const string& s, int left, vector<string>& current) {
        if (left == n)
            ans.emplace_back(current);
        for (int right = left; right < n; ++right) {
            current.emplace_back(s.substr(left, right - left + 1));
            if (IsPalindrome(current.back()))
                dfs(s, right + 1, current);
            current.pop_back();
        }
    }

    bool IsPalindrome(const string& s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != s[n - 1 - i])
                return false;
        }
        return true;
    }
};
