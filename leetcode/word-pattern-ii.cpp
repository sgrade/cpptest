// 291. Word Pattern II
// https://leetcode.com/problems/word-pattern-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        return backtrack(pattern, s, 0, 0);
    }
private:
    unordered_map<char, string> m;
    unordered_set<string> used_candidates;
    bool backtrack(const string& pattern, const string& s, int p_idx, int s_idx) {
        if (p_idx == pattern.size() && s_idx == s.size()) {
            return true;
        }
        if (p_idx == pattern.size() || s_idx == s.size()) {
            return false;
        }
        char ch = pattern[p_idx];
        if (m.find(ch) != m.end()) {
            string match = s.substr(s_idx, m[ch].size());
            if (match == m[ch]) {
                return backtrack(pattern, s, p_idx + 1, s_idx + match.size());
            }
            else {
                return false;
            }
        }
        for (int len = 1; s_idx + len <= s.size(); ++len) {
            string candidate = s.substr(s_idx, len);
            if (used_candidates.find(candidate) != used_candidates.end()) continue;
            m.emplace(pair<char, string>{ch, candidate});
            used_candidates.emplace(candidate);
            if (backtrack(pattern, s, p_idx + 1, s_idx + len)){
                return true;
            }
            m.erase(ch);
            used_candidates.erase(candidate);
        }
        return false;
    }
};
