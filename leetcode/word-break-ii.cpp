// 140. Word Break II
// https://leetcode.com/problems/word-break-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Dynamic Programming - Memoization
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        words.insert(wordDict.begin(), wordDict.end());
        return dfs(s);
    }

private:
    unordered_set<string> words;
    unordered_map<string, vector<string>> memo;
    vector<string> dfs(const string& remaining_s) {
        if (memo.find(remaining_s) != memo.end())
            return memo[remaining_s];
        // Base case
        if (remaining_s.empty())
            return {""};
        vector<string> ans;
        for (int i = 1; i <= remaining_s.size(); ++i) {
            string current_word = remaining_s.substr(0, i);
            if (words.find(current_word) != words.end()) {
                for (const string& next_word : dfs(remaining_s.substr(i))) {
                    ans.emplace_back(current_word + (next_word.empty() ? "" : " ") + next_word);
                }
            }
        }
        memo[remaining_s] = ans;
        return ans;
    }
};
