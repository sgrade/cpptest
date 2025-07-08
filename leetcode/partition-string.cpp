// 3597. Partition String
// https://leetcode.com/problems/partition-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
        vector<string> ans;
        string cur;
        int i = 0;
        for (const char& ch: s) {
            cur += ch;
            if (seen.find(cur) == seen.end()) {
                seen.emplace(cur);
                ans.emplace_back(cur);
                cur = "";
                ++i;
            }
        }
        return ans;
    }
};
