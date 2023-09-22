// 859. Buddy Strings
// https://leetcode.com/problems/buddy-strings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        vector<int> indexes_of_not_equal;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) {
                indexes_of_not_equal.emplace_back(i);
                if (indexes_of_not_equal.size() > 2)
                    return false;
            }
        }
        if (indexes_of_not_equal.size() == 2) {
            if (s[indexes_of_not_equal[0]] == goal[indexes_of_not_equal[1]] && 
            s[indexes_of_not_equal[1]] == goal[indexes_of_not_equal[0]])
                return true;
        }
        else if (indexes_of_not_equal.size() == 0) {
            vector<int> counter(26);
            for (const char& ch: s) {
                ++counter[ch - 'a'];
                if (counter[ch - 'a'] > 1)
                    return true;
            }
        }
        return false;
    }
};
